/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:28:30 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/30 10:26:03 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print(char c, va_list ap)
{
	int	total;

	total = 0;
	if (c == 'c')
		total = write(1, &(char){va_arg(ap, int)}, 1);
	else if (c == 's')
		total = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		total = ft_putadr(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		total = ft_put(va_arg(ap, int));
	else if (c == 'u')
		total = ft_putun(va_arg(ap, int), "0123456789", 0);
	else if (c == 'x')
		total = ft_putun(va_arg(ap, unsigned int), "0123456789abcdef", 1);
	else if (c == 'X')
		total = ft_putun(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
	else if (c == '%')
		total = write(1, "%", 1);
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			total += ft_print(format[++i], ap);
		else
			total += write(1, &format[i], 1);
		i++;
	}
	return (total);
}
/*
int main()
{
	write(1, &(char){ft_printf("allo %d\n", 0) + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){ft_printf("allo %x\n", 0) + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %d\n", 0) +48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %x\n", 0) +48}, 1);
	write(1, "\n", 1);
	write(1, &(char){ft_printf("allo %%\n") + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){ft_printf("allo %c\n", 'c') + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %%\n") + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %c\n", 'c') + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){ft_printf("allo %s\n", "maman") + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %s\n", "maman") + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){ft_printf("allo %p\n", NULL) + 48}, 1);
	write(1, "\n", 1);
	write(1, &(char){printf("allo %s\n", NULL) + 48}, 1);
	write(1, "\n", 1);
	return 0;
}
*/
