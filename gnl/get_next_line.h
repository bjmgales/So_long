/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:03:21 by bgales            #+#    #+#             */
/*   Updated: 2022/05/27 12:12:37 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strchr(char *s1, int c);
int		ft_strlen(char *string);
char	*get_next_line(int fd);
char	*ft_selectafternl(char *s1);
char	*ft_selectbeforenl(char *newline);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char *first, char *then);
char	*ft_strdeux(char *s1);
char	*ft_strdup(char *s);
void	print_and_exit(char *str);
#endif
