/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:39:26 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/24 10:39:28 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	hay = (char *)str;
	if (to_find[0] == '\0')
		return (hay);
	while (hay[i] && i < n)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j]
			&& i + j < n)
			j++;
		if (to_find[j] == '\0')
			return (hay + i);
		i++;
	}
	return (0);
}
