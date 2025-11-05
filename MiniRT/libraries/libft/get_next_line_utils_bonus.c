/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:30:55 by shvalma           #+#    #+#             */
/*   Updated: 2024/12/12 16:52:39 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (0);
}	

char	*ft_dup(char *str, int nb)
{
	int		i;
	char	*dupstr;
	int		len;

	i = 0;
	if (!nb)
		len = ft_strlen(str);
	else
		len = nb;
	dupstr = malloc(sizeof(char) * (len + 1));
	if (dupstr == NULL)
		return (free(str), NULL);
	while (str[i] && i < len)
	{	
		dupstr[i] = str[i];
		i++;
	}
	dupstr[i] = 0;
	return (dupstr);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (s2 == NULL)
		return ;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = 0;
}
