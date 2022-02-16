/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjm <bjm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:01:02 by bjm               #+#    #+#             */
/*   Updated: 2022/02/16 15:21:16 by bjm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "./gnl/get_next_line.h"

int_bag_4 *mapcheck_height(const char *map)
{
	int	fd;
	char *tocheck[21];
	int_bag_4 *coordinates;
	int y;
	int x;
	
	y = 0;
	x = 0;
	fd = open(map, O_RDONLY);
	coordinates = malloc(sizeof(int_bag_4));
	while (x < 21)
	{
		tocheck[x++] = get_next_line(fd);
	}
	close(fd);
	x = ft_strlen(tocheck[0]);
	if (tocheck[20] != NULL || x > 20)
	{
		printf("ERROR : map is too big\n");
		free (coordinates);
		exit(0);
	}
	while (tocheck[y] != NULL)
	{
		if (x != ft_strlen(tocheck[y]) || tocheck[2] == NULL || 3 > ft_strlen(tocheck[0]))
		{
			printf("ERROR : map is not a rectangle.\n");
			free(coordinates);
			exit(0);
		}
		free(tocheck[y++]);
	}
	printf("lol\n");
	*coordinates->full_width = x - 1;
	*coordinates->full_height = y;

	return (coordinates);
}

int main(void)
{
	int_bag_4 *test;
	test = mapcheck_height("./maps/test.ber");
	if (!test)
		printf("lol\n");
	printf("width : %d height : %d", *test->full_width, *test->full_height);
	
}