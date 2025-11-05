/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:34:53 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/30 10:08:09 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putunbr(unsigned int x, char *base, int b);
int		ft_putun(unsigned int x, char *base, int b);
void	ft_putnbr(int x);
int		ft_put(int x);
int		ft_putstr(char *str);
int		ft_putadr(void *adr);
int		ft_printf(const char *format, ...);

#endif
