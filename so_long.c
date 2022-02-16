/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:52:09 by bgales            #+#    #+#             */
/*   Updated: 2022/02/16 13:05:19 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int key, void_bag_2 *software)
{
	printf(" Pressed key id : %d\n", key);
	return (0)
}

int mapcheck(const char *map)
{
	int	fd;
	int lencheck;
	int h;
	char *tocheck[20];

	h = 0;
	fd = open(map, O_RDONLY);

	while (h < 20)
	{
		tocheck[h] = malloc(sizeof(char *) * 20);
		tocheck[h++] = get_next_line(fd);
	}
	if (tocheck[20] != NULL)
	{
		printf("ERROR : map is too big\n");
		return (0);
	}
	close(fd);
	h = 0;
	lencheck = ft_strlen(tocheck[0]);
	while (tocheck[h] != NULL)
	{
		if (lencheck != ft_strlen(tocheck[h]));
		{
			printf("ERROR : map is not a rectangle.\n")
			return (0);
		}
	}
	return (lencheck)
}
void so_long(const char *map)
{
	void_bag_2	*software;
	int_bag_4	*coordinates;
	images		image;
	int	x;

	software = malloc(sizeof(void_bag_2));
	coordinates = malloc(sizeof(int_bag_4));
	image = malloc(sizeof(images));
	x = map_check(map);
	if (i == 0)
		return;
	software->game_ptr = mlx_init();
	software->win_ptr = mlx_new_window(software->mlx_ptr, (x * 10), 200, "test");
	mlx_loop(mlx_ptr);
}

int main(void)
{
	so_long("./maps/test.ber");
}
