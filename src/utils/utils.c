/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:18:01 by bgales            #+#    #+#             */
/*   Updated: 2023/04/28 18:22:06 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_y(const char *map_path)
{
	char	*test;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(map_path, O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
		ret++;
		free (test);
		test = get_next_line(fd);
	}
	free (test);
	return (ret);
}

void	ft_init(t_chars *z)
{
	z->p = 0;
	z->c = 0;
	z->e = 0;
	z->i = 0;
	z->line = -1;
}
