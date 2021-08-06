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

static void	parse_first_line(char *line, t_game_info *game_info)
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
	ft_lstadd_back(&(game_info->map_rows), ft_lstnew(line_ptr));
	if (map_width == -1)
		quit_with_error(ERR_INVALID_MAP, game_info);
	game_info->map_height++;
	game_info->map_width = map_width;
}

static int	parse_line(char *line, t_game_info *game_info)
{
	int	line_len;
	int	i;

	if (*line != '1')
		return (-1);
	line_len = ft_strlen(line);
	if (line_len != game_info->map_width)
		return (-2);
	if (line[line_len - 1] != '1')
		return (-3);
	i = 1;
	while (i < line_len)
		if (ft_strchr("01PEC", line[i++]) == NULL)
			return (-4);
	ft_lstadd_back(&(game_info->map_rows), ft_lstnew(line));
	game_info->map_height++;
	return (1);
}

void	validate_map(int fd, t_game_info *game_info)
{
	char	*line;
	int		result;

	result = get_next_line(fd, &line);
	if (result == -1)
		quit_with_error(errno, game_info);
	parse_first_line(line, game_info);
	if (game_info->map_width == -1)
		quit_with_error(ERR_INVALID_MAP, game_info);
	while (1)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			quit_with_error(errno, game_info);
		if (result == 0)
			break ;
		if (parse_line(line, game_info) < 0)
			quit_with_error(ERR_INVALID_MAP, game_info);
	}
	free(line);
	line = ft_lstlast(game_info->map_rows)->content;
	while (*line)
		if (*line++ != '1')
			quit_with_error(ERR_INVALID_MAP, game_info);
}

void	parse_map(t_game_info *game_info)
{
	int	map_size;

	map_size = game_info->map_width * game_info->map_height;
	game_info->map = ft_calloc(map_size, 1);
	if (game_info->map == NULL)
		quit_with_error(errno, game_info);
	generate_map(game_info);
	dump_info(game_info);
	print_map(game_info);
}

void	get_map(t_game_info *game_info)
{
	int	fd;

	fd = open(game_info->map_filename, O_RDONLY);
	if (fd < 0)
		quit_with_error(errno, game_info);
	game_info->map_fd = fd;
	validate_map(fd, game_info);
	close(fd);
	parse_map(game_info);
}
