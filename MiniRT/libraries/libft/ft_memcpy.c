/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:24:44 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/24 10:24:46 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char	*str;
	char	*scr;
	int		i;

	i = 0;
	str = (char *)dest;
	scr = (char *)src;
	if (!src && !dest)
		return (dest);
	while (n)
	{
		str[i] = scr[i];
		i++;
		n--;
	}
	return (dest);
}
