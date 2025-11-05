/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:40:58 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/24 10:41:02 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	trimlen(char const *s1, char const *set)
{
	size_t	deb;
	size_t	fin;
	size_t	len;

	deb = 0;
	fin = ft_strlen(s1);
	while (s1[deb] && ft_strchr(set, s1[deb]))
		deb++;
	while (fin > deb && ft_strchr(set, s1[fin - 1]))
		fin--;
	len = fin - deb;
	return (len);
}

static char	*trimmage(const char *s1, size_t deb, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[deb + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	deb;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	deb = 0;
	len = trimlen(s1, set);
	while (s1[deb] && ft_strchr(set, s1[deb]))
		deb++;
	return (trimmage(s1, deb, len));
}
