/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:34:15 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/30 09:45:37 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putunbr(unsigned int x, char *base, int b)
{
	if (b == 0)
	{
		if (x > 9)
			ft_putunbr(x / 10, base, b);
		write(1, &base[x % 10], 1);
	}
	if (b == 1)
	{	
		if (x > 15)
			ft_putunbr(x / 16, base, b);
		write(1, &base[x % 16], 1);
	}
}

int	ft_putun(unsigned int x, char *base, int b)
{
	int				total;
	unsigned int	nb;

	total = 1;
	nb = x;
	if (b == 0)
	{	
		while (nb > 9)
		{
			total++;
			nb /= 10;
		}
	}
	if (b == 1)
	{
		while (nb > 15)
		{	
			total++;
			nb /= 16;
		}
	}
	ft_putunbr(x, base, b);
	return (total);
}

void	ft_putnbr(int x)
{
	if (x == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (x < 0)
	{
		write(1, "-", 1);
		x = -x;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	write(1, &(char){x % 10 + 48}, 1);
}

int	ft_put(int x)
{
	int				total;
	unsigned int	nb;

	total = 1;
	if (x < 0)
	{
		total++;
		nb = (unsigned int)-x;
	}
	else
		nb = (unsigned int)x;
	while (nb > 9)
	{	
		total++;
		nb /= 10;
	}
	ft_putnbr(x);
	return (total);
}
