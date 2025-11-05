/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:36:46 by shvalma           #+#    #+#             */
/*   Updated: 2024/11/17 23:33:39 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strcat(char *s1, char *tab, int *len)
{
	char	*final;
	int		i;

	if (tab == NULL)
		return (s1);
	i = ft_strlen(tab);
	*len += i;
	if (i == 0)
		return (s1);
	final = malloc(sizeof(char) * *len + 1);
	if (final == NULL)
		return (free(s1), NULL);
	final[0] = 0;
	if (tab == NULL)
		return (final);
	ft_strcpy(final, s1);
	free(s1);
	ft_strcpy(&final[*len - i], tab);
	return (final);
}

char	*add(char *final, int fd)
{
	int		rd;
	char	tab[BUFFER_SIZE + 1];
	int		count;
	int		len;

	len = ft_strlen(final);
	rd = read(fd, tab, BUFFER_SIZE);
	tab[rd] = 0;
	while (rd > 0)
	{
		count = 0;
		final = ft_strcat(final, tab, &len);
		if (final == NULL)
			return (NULL);
		count = ft_check(final);
		if (count)
			return (tab[0] = 0, final);
		rd = read(fd, tab, BUFFER_SIZE);
		if (rd <= 0)
			return (tab[0] = 0, final);
		tab[rd] = 0;
	}
	return (final);
}

char	*get_next_line(int fd)
{
	static char		*newline[FD_MAX];
	char			*final;
	char			*temp;
	int				count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(newline[fd]), newline[fd] = NULL, NULL);
	newline[fd] = add(newline[fd], fd);
	if (newline[fd] == NULL || newline[fd][0] == 0)
		return (free(newline[fd]), newline[fd] = NULL, NULL);
	count = ft_check(newline[fd]);
	temp = newline[fd];
	final = ft_dup(newline[fd], count);
	if (count)
	{	
		newline[fd] = ft_dup(&newline[fd][count], 0);
		return (free(temp), final);
	}
	else
		return (free(temp), newline[fd] = NULL, final);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int     fd;
	char    *line;
	int     line_count;

	// Test 1: Reading from a regular file
	printf("\n=== Test 1: Reading from a regular file ===\n");
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
        	return (1);
    	}
    	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s\n", line_count++, line);
		free(line);
	}
	close(fd);
	return 0;
}
*/
