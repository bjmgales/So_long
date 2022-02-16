/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjm <bjm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:52:09 by bgales            #+#    #+#             */
/*   Updated: 2022/02/16 15:13:26 by bjm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int key, void_bag_2 *software)
{
	printf(" Pressed key id : %d\n", key);
	return (0)
}

int_bag_4 *mapcheck_height(const char *map)
{
	int	fd;
	char **tocheck;
	int_bag_4 *coordinates=NULL;
	int y;
	int x;
	
	y = 0;
	x = 0;
	fd = open(map, O_RDONLY);
	while (x < 30)
	{
		tocheck[x++] = get_next_line(fd);
	}
	close(fd);
	if (tocheck[20] != NULL || tocheck[])
	{
		printf("ERROR : map is too big\n");
		exit(0);
	}
	x = ft_strlen(tocheck[0]);
	while (tocheck[++y] != NULL)
	{
		if (x != ft_strlen(tocheck[y]))
		{
			printf("ERROR : map is not a rectangle.\n");
			exit(0);
		}
		free(tocheck[y]);
	}
	coordinates=malloc(sizeof(int_bag_4));
	*coordinates->full_width = x - 1;
	*coordinates->full_height = y - 1;

	return (coordinates);
}
void so_long(const char *map)
{
	void_bag_2	*software;
	int_bag_4	*coordinates;
	images		*image;

	software = malloc(sizeof(void_bag_2));
	image = malloc(sizeof(images));
	coordinates = mapcheck_height(map);
	if (i == 0)
		return;
	software->game_ptr = mlx_init();
	software->win_ptr = mlx_new_window(software->game_ptr, (*coordinates->full_width * 10), (*coordinates->full_height * 40), "test");
	mlx_loop(software->game_ptr);
}

int main(void)
{
	so_long("./maps/test.ber");
}
