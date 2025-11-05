/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:34:27 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/30 10:28:30 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	total;

	total = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		write(1, str++, 1);
		total++;
	}
	return (total);
}

int	countadr(unsigned long long adr)
{
	int	count;

	count = 1;
	while (adr > 15)
	{
		count++;
		adr = adr / 16;
	}
	return (count);
}

void	ft_putad(unsigned long long adr, char *base)
{
	if (adr > 15)
		ft_putad((adr / 16), base);
	write(1, &base[adr % 16], 1);
}

int	ft_putadr(void *adr)
{
	unsigned long long	adrs;

	if (adr == NULL)
		return (write(1, "0x0", 3));
	adrs = (unsigned long long)adr;
	write(1, "0x", 2);
	ft_putad(adrs, "0123456789abcdef");
	return (countadr(adrs) + 2);
}
