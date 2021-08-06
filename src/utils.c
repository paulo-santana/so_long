#include "utils.h"

void dump_info(t_game_info *game)
{
	printf("program name: %s\n", game->program_name);
	printf("map name: %s\n", game->map_filename);
	printf("map width x height: %dx%d\n", game->map_width, game->map_height);
}

void print_map(t_game_info *gi)
{
	int i = 0;
	int map_size = gi->map_height * gi->map_width;

	while (i < map_size)
	{
		ft_putchar_fd((gi->map)[i], 1);
		i++;
		if (i % gi->map_width == 0)
			ft_putchar_fd('\n', 1);
	}

}
