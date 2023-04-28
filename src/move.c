/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:46:04 by bgales            #+#    #+#             */
/*   Updated: 2022/06/02 14:26:26 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	endgame(t_game *g)
{
	mlx_destroy_window(g->soft, g->win);
	ft_printf("Well played !\n");
	exit (0);
}

int	move_right(t_game *g, int key)
{
	int		l;
	int		i;

	l = -1;
	i = -1;
	while (++l < g->map_h)
	{
		while (g->map[l][++i] != '\0')
			if (g->map[l][i] == 'P')
				break ;
		if (g->map[l][i] == 'P' && (g->map[l][i + 1] == '0' || g->map[l][i + 1]
		== 'C' || (g->map[l][i + 1] == 'E' && g->c_nbr == 0)))
			move_right_norm(g, l, i, key);
		i = -1;
	}
	return (0);
}

int	move_left(t_game *g, int key)
{
	int		l;
	int		i;

	l = -1;
	i = -1;
	while (++l < g->map_h)
	{
		while (g->map[l][++i] != '\0')
			if (g->map[l][i] == 'P')
				break ;
		if (g->map[l][i] == 'P' && (g->map[l][i - 1] == '0' || g->map[l][i - 1]
		== 'C' || (g->map[l][i - 1] == 'E' && g->c_nbr == 0)))
			move_left_norm(g, l, i, key);
		i = -1;
	}
	return (0);
}

int	move_up(t_game *g, int key)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (l < g->map_h)
	{
		while (g->map[l][i] != '\0')
		{
			if (g->map[l][i] == 'P')
				break ;
			i++;
		}
		if (g->map[l][i] == 'P' && (g->map[l - 1][i] == '0'
		|| g->map[l - 1][i] == 'C' || (g->map[l - 1][i] == 'E'
		&& g->c_nbr == 0)))
			move_up_norm(g, l, i, key);
		l++;
		i = 0;
	}
	return (0);
}

int	move_down(t_game *g, int key)
{
	int		l;
	int		i;

	l = -1;
	i = -1;
	while (++l < g->map_h)
	{
		while (g->map[l][++i] != '\0')
			if (g->map[l][i] == 'P')
				break ;
		if (g->map[l][i] == 'P' && (g->map[l + 1][i] == '0' ||
			g->map[l + 1][i] == 'C'
		|| (g->map[l + 1][i] == 'E' && g->c_nbr == 0)))
		{
			move_down_norm(g, l, i, key);
			l++;
		}
		i = -1;
	}
	return (0);
}
