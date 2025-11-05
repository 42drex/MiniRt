/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:03:38 by shvalma           #+#    #+#             */
/*   Updated: 2024/12/12 16:53:29 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_strcpy(char *s1, char *s2);
char	*ft_dup(char *str, int nb);
int		ft_check(char	*str);
int		ft_strlen_get(const char *str);
char	*ft_strcat(char *s1, char *tab, int *len);
char	*add(char *final, int fd);
char	*get_next_line(int fd);
void	ft_strcpy2(char *s1, char *s2);

#endif
