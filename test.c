/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:01:02 by bjm               #+#    #+#             */
/*   Updated: 2022/02/16 21:20:10 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "./gnl/get_next_line.h"

int mapcheck(char **map, int_bag_4 *coordinates)
{
	int	i;
	int	j;
	char *PIE_check=NULL;

	i = 0;
	j = ft_strlen(map[i]) - 2;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			free (coordinates);
			printf("Error \n Map is not surrounded by walls");
			return (1);
		}
		if (ft_strlen(map[i]) != (j + 2))
		{
			printf("Eroor\n Map is not a rectangle");
			free(coordinates);
			return (1);
		}
		i++;
	}
	i--;
	j = 0;
	if (map[2] == NULL || ft_strlen(map[i]) < 3)
	{
		free(coordinates);
		printf("Error\n Map is too small");
		return (1);
	}
	while (map[0][j] < (ft_strlen(map[0]) - 2) && map[i][j] < (ft_strlen(map[0]) - 2))
	{
		if (map[0][j] != '1' || map[i][j] != '1' )
		{
			free (coordinates);
			printf("Error \n Map is not surrounded by walls");
			return (1);
		}
		j++;
	}
	i = -1;
	while (map[++i] != NULL)
		PIE_check = ft_strjoin(PIE_check, map[i]);
	if (!ft_strchr(PIE_check, 'P') || !ft_strchr(PIE_check, 'I') || !ft_strchr(PIE_check, 'E'))
	{
		free(coordinates);
		printf("Error\n Map is missing elements");
		return (1);
	}
	return (0);
}
int_bag_4 *map_init(const char *map)
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
		tocheck[x++] = get_next_line(fd);
	close(fd);
	x = ft_strlen(tocheck[0]);
	if (mapcheck(tocheck, coordinates) == 1)
	{
		while (tocheck[y] != NULL)
			free(tocheck[y++]);
		return (NULL);
	}
	while (tocheck[y] != NULL)
		free(tocheck[y++]);
	coordinates->full_width = x - 1;
	coordinates->full_height = y;
	return (coordinates);
}

int main(void)
{
	int_bag_4 *test;
	test = map_init("./maps/test.ber");
	if (!test)
		printf("lol\n");
	printf("width : %d height : %d", test->full_width, test->full_height);

}
