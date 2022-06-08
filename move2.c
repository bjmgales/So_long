/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:05:59 by bgales            #+#    #+#             */
/*   Updated: 2022/06/02 14:12:12 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(int key, t_game *g)
{
	char	*str;

	if (key == 2 || key == 0 || key == 1 || key == 13)
	{
		str = ft_itoa(g->c_mv);
		ft_printf("Move count : %d\n", g->c_mv);
		mlx_put_image_to_window(g->soft, g->win, g->wall, 0, 0);
		mlx_string_put(g->soft, g->win, 0, 0, 123, str);
		free (str);
	}
}

void	move_right_norm(t_game *g, int l, int i, int key)
{
	char	tmp;

	tmp = '\0';
	g->c_mv++;
	print_move(key, g);
	if (g->map[l][i + 1] == 'C')
		g->c_nbr--;
	if (g->c_nbr == 0 && g->map[l][i + 1] == 'E')
		endgame(g);
	mlx_put_image_to_window(g->soft, g->win, g->floor, i * 32, l * 32);
	mlx_put_image_to_window(g->soft, g->win, g->p, (i + 1) * 32, l * 32);
	tmp = g->map[l][i + 1];
	if (tmp == 'C')
		tmp = '0';
	g->map[l][i + 1] = g->map[l][i];
	g->map[l][i] = tmp;
}

void	move_left_norm(t_game *g, int l, int i, int key)
{
	char	tmp;

	tmp = '\0';
	g->c_mv++;
	print_move(key, g);
	if (g->map[l][i - 1] == 'C')
				g->c_nbr--;
	if (g->c_nbr == 0 && g->map[l][i - 1] == 'E')
		endgame(g);
	mlx_put_image_to_window(g->soft, g->win,
		g->floor, i * 32, l * 32);
	mlx_put_image_to_window(g->soft, g->win,
		g->p, (i - 1) * 32, l * 32);
	tmp = g->map[l][i - 1];
	if (tmp == 'C')
		tmp = '0';
	g->map[l][i - 1] = g->map[l][i];
	g->map[l][i] = tmp;
}

void	move_up_norm(t_game *g, int l, int i, int key)
{
	char	tmp;

	tmp = '\0';
	g->c_mv++;
	print_move(key, g);
	if (g->map[l - 1][i] == 'C')
				g->c_nbr--;
	if (g->c_nbr == 0 && g->map[l - 1][i] == 'E')
		endgame(g);
	mlx_put_image_to_window(g->soft, g->win, g->floor, i * 32, l * 32);
	mlx_put_image_to_window(g->soft, g->win, g->p, i * 32, (l - 1) * 32);
	tmp = g->map[l - 1][i];
	if (tmp == 'C')
		tmp = '0';
	g->map[l - 1][i] = g->map[l][i];
	g->map[l][i] = tmp;
}

void	move_down_norm(t_game *g, int l, int i, int key)
{
	char	tmp;

	tmp = '\0';
	g->c_mv++;
	print_move(key, g);
	if (g->map[l + 1][i] == 'C')
			g->c_nbr--;
	if (g->c_nbr <= 0 && g->map[l + 1][i] == 'E')
		endgame(g);
	mlx_put_image_to_window(g->soft, g->win, g->floor, i * 32, l * 32);
	mlx_put_image_to_window(g->soft, g->win, g->p, i * 32, (l + 1) * 32);
	tmp = g->map[l + 1][i];
	if (tmp == 'C')
		tmp = '0';
	g->map[l + 1][i] = g->map[l][i];
	g->map[l][i] = tmp;
}
