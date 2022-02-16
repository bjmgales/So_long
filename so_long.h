/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:52:16 by bgales            #+#    #+#             */
/*   Updated: 2022/02/16 21:25:31 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./minilibx/mlx.h"

struct images
{
	void * img_ptr;
	void * map_ptr;
};
typedef struct images images;

struct void_bag_2
{
	void *game_ptr;
	void *win_ptr;

};
typedef struct void_bag_2 void_bag_2;

struct int_bag_4
{
	int *x;
	int	*y;
	int full_width;
	int full_height;
};
typedef struct int_bag_4 int_bag_4;

int_bag_4 *map_init(const char *map);
int mapcheck(char **map, int_bag_4 *coordinates);
void	so_long(const char *map);

# endif
