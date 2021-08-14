#include "utils.h"

void	print_coordinates(size_t pos, int width)
{
	printf("%lux%lu",
		pos / width,
		pos % width);
}

void	dump_info(t_game_state *game)
{
	printf("program name: %s\n", game->program_name);
	printf("map name: %s\n", game->map_filename);
	printf("map dimensions: %dx%d\n", game->map.width, game->map.height);
	printf("player position: ");
	print_coordinates(game->player_pos, game->map.width);
	printf("\n");
	printf("moves: %lu\n", game->movement_count);
	printf("collectibles: %lu/%lu\n", game->collected_collectibles,
		game->total_collectibles);
}

void	print_map(t_game_state *gi)
{
	int	i;

	i = 0;
	while (i < gi->map.height)
	{
		write(1, &gi->map_mem[i * gi->map.width], gi->map.width);
		i++;
		ft_putchar_fd('\n', 1);
	}
}
