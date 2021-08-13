/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:50:31 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/05 02:50:31 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

static void	parse_first_line(char *line, t_game_state *state)
{
	int		map_width;
	char	*line_ptr;

	map_width = 0;
	line_ptr = line;
	while (*line)
	{
		if (*line++ == '1')
			map_width++;
		else
		{
			map_width = -1;
			break ;
		}
	}
	ft_lstadd_back(&(state->map_rows), ft_lstnew(line_ptr));
	if (map_width == -1)
		quit_with_error(ERR_INVALID_MAP, state);
	state->map.height++;
	state->map.width = map_width;
}

static int	parse_line(char *line, t_game_state *state)
{
	int	line_len;
	int	i;

	if (*line != '1')
		return (-1);
	line_len = ft_strlen(line);
	if (line_len != state->map.width)
		return (-2);
	if (line[line_len - 1] != '1')
		return (-3);
	i = 1;
	while (i < line_len)
		if (ft_strchr("01PEC", line[i++]) == NULL)
			return (-4);
	ft_lstadd_back(&(state->map_rows), ft_lstnew(line));
	state->map.height++;
	return (1);
}

void	validate_map(int fd, t_game_state *state)
{
	char	*line;
	int		result;

	result = get_next_line(fd, &line);
	if (result == -1)
		quit_with_error(errno, state);
	parse_first_line(line, state);
	if (state->map.width == -1)
		quit_with_error(ERR_INVALID_MAP, state);
	while (1)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			quit_with_error(errno, state);
		if (result == 0)
			break ;
		if (parse_line(line, state) < 0)
			quit_with_error(ERR_INVALID_MAP, state);
	}
	free(line);
	line = ft_lstlast(state->map_rows)->content;
	while (*line)
		if (*line++ != '1')
			quit_with_error(ERR_INVALID_MAP, state);
}

void	parse_map(t_game_state *state)
{
	int	map_size;

	map_size = state->map.width * state->map.height;
	state->map_mem = ft_calloc(map_size, 1);
	if (state->map_mem == NULL)
		quit_with_error(errno, state);
}

void	get_map(t_game_state *state)
{
	int	fd;

	fd = open(state->map_filename, O_RDONLY);
	if (fd < 0)
		quit_with_error(errno, state);
	state->map_fd = fd;
	validate_map(fd, state);
	close(fd);
	parse_map(state);
	generate_map(state);
	dump_info(state);
	print_map(state);
}
