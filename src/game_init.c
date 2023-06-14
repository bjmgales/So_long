/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:53:29 by bgales            #+#    #+#             */
/*   Updated: 2023/04/28 18:10:27 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(const char *map_path, t_game *game_ptr)
{
	int		fd;
	int		line;
	char	**ret;

	line = get_y(map_path);
	ret = NULL;
	if (open(map_path, O_DIRECTORY) > 0)
		print_and_exit("Error\n file is needed.");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error\n Map file not found.");
	game_ptr->map_h = -1;
	while (++game_ptr->map_h < line)
	{
		game_ptr->map[game_ptr->map_h] = get_next_line(fd);
		del_nl(game_ptr->map[game_ptr->map_h]);
	}
	game_ptr->map_w = ft_strlen(game_ptr->map[0]);
	return (ret);
}

void	load_texture(t_game *game_ptr)
{
	game_ptr->exit = mlx_xpm_file_to_image(game_ptr->soft,
			"./ressources/image/exit.xpm", &game_ptr->height, &game_ptr->width);
	game_ptr->item = mlx_xpm_file_to_image(game_ptr->soft,
			"./ressources/image/item.xpm", &game_ptr->height, &game_ptr->width);
	game_ptr->p = mlx_xpm_file_to_image(game_ptr->soft,
			"./ressources/image/player.xpm", &game_ptr->height, &game_ptr->width);
	game_ptr->wall = mlx_xpm_file_to_image(game_ptr->soft,
			"./ressources/image/wall.xpm", &game_ptr->height, &game_ptr->width);
	game_ptr->floor = mlx_xpm_file_to_image(game_ptr->soft,
			"./ressources/image/floor.xpm", &game_ptr->height, &game_ptr->width);
}

int	item_nb(t_game *game_ptr)
{
	int	l;
	int	i;
	int	ret;

	l = 0;
	i = 0;
	ret = 0;
	while (l < game_ptr->map_h)
	{
		while (game_ptr->map[l][i])
		{
			if (game_ptr->map[l][i] == 'C')
				ret++;
			i++;
		}
		i = 0;
		l++;
	}
	return (ret);
}

int	move_player(int key, t_game *g)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	if (key == 2)
		return (move_right(g, key));
	if (key == 0)
		return (move_left(g, key));
	if (key == 1)
		return (move_down(g, key));
	if (key == 13)
		return (move_up(g, key));
	if (key == 53)
	{
		mlx_destroy_window(g->soft, g->win);
		print_and_exit("Goodbye thanks for playing \n");
	}
	return (0);
}

void	so_long(const char *map_path)
{
	t_game	game_ptr;

	get_map(map_path, &game_ptr);
	game_ptr.soft = mlx_init();
	check_map(&game_ptr);
	load_texture(&game_ptr);
	game_ptr.win = mlx_new_window(game_ptr.soft, game_ptr.map_w * 32,
			game_ptr.map_h * 32, "So_long");
	print_map(game_ptr);
	game_ptr.c_nbr = item_nb(&game_ptr);
	game_ptr.c_mv = 0;
	mlx_hook(game_ptr.win, 02, 0L, move_player, &game_ptr);
	mlx_hook(game_ptr.win, 17, 0, endgame, &game_ptr);
	mlx_loop(game_ptr.soft);
	return ;
}
