/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:53:59 by bgales            #+#    #+#             */
/*   Updated: 2022/06/02 14:09:32 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include <mlx.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_chars {
	int	p;
	int	c;
	int	e;
	int	line;
	int	i;
}	t_chars;

struct s_game
{
	char	**map;
	void	*p;
	void	*item;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*soft;
	void	*win;
	int		width;
	int		height;
	int		map_h;
	int		map_w;
	int		c_nbr;
	int		c_mv;
};
typedef struct s_game	t_game;

char	**get_map(const char *map_path, t_game *game_ptr);
void	print_move(int key, t_game *g);
void	movecount(int key, t_game *g);
void	check_map(t_game *game_ptr);
void	print_map(t_game game_ptr);
int		endgame(t_game *g);
int		move_up(t_game *game_ptr, int key);
int		move_down(t_game *game_ptr, int key);
int		move_right(t_game *g, int key);
int		move_left(t_game *game_ptr, int key);
void	del_nl(char *str);
void	ft_init(t_chars *z);
void	move_right_norm(t_game *g, int l, int i, int key);
void	move_left_norm(t_game *g, int l, int i, int key);
void	move_up_norm(t_game *g, int l, int i, int key);
void	move_down_norm(t_game *g, int l, int i, int key);
void	so_long(const char *map_path);
int		height_map(t_game *g);
int		get_y(const char *map_path);
void	print_and_exit(char *str);
void	load_texture(t_game *game_ptr);
#endif
