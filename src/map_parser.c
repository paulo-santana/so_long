
#include "so_long.h"

int	parse_first_line(char *line)
{
	int	i;
	int	map_width;

	map_width = 0;
	i = 0;
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
	return (map_width);
}

void	parse_map(int fd, t_game_info *game_info)
{
	char	*line;
	int		result;
	int		map_width;

	(void) game_info;
	result = get_next_line(fd, &line);
	if (result == -1)
		quit_with_error(errno);
	map_width = parse_first_line(line);
	free(line);
	if (map_width == -1)
		quit_with_error(ERR_INVALID_MAP);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		ft_putendl_fd(line, 1);
		free(line);
	}
}

void	get_map(t_game_info *game_info)
{
	int	fd;

	fd = open(game_info->map_filename, O_RDONLY);
	if (fd < 0)
		quit_with_error(errno);
	parse_map(fd, game_info);
}
