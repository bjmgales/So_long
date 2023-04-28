/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:22:39 by bgales            #+#    #+#             */
/*   Updated: 2022/06/02 14:11:10 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_and_exit(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	del_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\n')
		if (str[i] == '\0')
			break ;
	if (str[i] == '\n')
		str[i] = '\0';
}

void	print_map(t_game game_ptr)
{
	int	l;
	int	i;

	l = -1;
	i = -1;
	while (++l < game_ptr.map_h)
	{
		while (game_ptr.map[l][++i])
		{
			if (game_ptr.map[l][i] == '1')
				mlx_put_image_to_window(game_ptr.soft,
					game_ptr.win, game_ptr.wall, i * 32, l * 32);
			if (game_ptr.map[l][i] == 'P')
				mlx_put_image_to_window(game_ptr.soft,
					game_ptr.win, game_ptr.p, i * 32, l * 32);
			if (game_ptr.map[l][i] == 'C')
				mlx_put_image_to_window(game_ptr.soft,
					game_ptr.win, game_ptr.item, i * 32, l * 32);
			if (game_ptr.map[l][i] == 'E')
				mlx_put_image_to_window(game_ptr.soft,
					game_ptr.win, game_ptr.exit, i * 32, l * 32);
		}
		i = -1;
	}
	return ;
}

void	pce_check(t_game *game_ptr)
{
	t_chars	*check;

	check = malloc(sizeof(t_chars));
	ft_init(check);
	while (++check->line < game_ptr->map_h)
	{
		while (game_ptr->map[check->line][++check->i])
		{
			if (game_ptr->map[check->line][check->i] == 'P')
				check->p++;
			if (game_ptr->map[check->line][check->i] == 'C')
				check->c++;
			if (game_ptr->map[check->line][check->i] == 'E')
				check->e++;
		}
		check->i = -1;
	}
	if (check->p != 1)
		print_and_exit("Error\n one player is needed.");
	if (check->e != 1)
		print_and_exit("Error\n one exit is needed.");
	if (check->c < 1)
		print_and_exit("Error\n at least one item is needed.");
	free (check);
}

void	check_map(t_game *game_ptr)
{
	int		i;
	int		line;

	i = -1;
	line = -1;
	while (++line < (game_ptr->map_h))
		if (ft_strlen(game_ptr->map[line]) != game_ptr->map_w)
			print_and_exit("Error\n map is nor a square or rectangle.");
	while (game_ptr->map[0][++i] != '\0'
	|| game_ptr->map[game_ptr->map_h - 1][i] != '\0')
		if (game_ptr->map[0][i] != '1' ||
		game_ptr->map[game_ptr->map_h - 1][i] != '1')
			print_and_exit("Error\n Map is not surrounded by walls.");
	pce_check(game_ptr);
	return ;
}
