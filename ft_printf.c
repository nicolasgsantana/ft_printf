/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:57 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/20 10:03:30 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
			// else if (format[i] == 'p')
			// 	// run something
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);
			// else if (format[i] == 'u')
			// 	// run something
			// else if (format[i] == 'x')
			// 	// run something
			// else if (format[i] == 'X')
			// 	// run something
			else if (format[i] == '%')
				ft_putchar_fd('%', STDOUT_FILENO);
			i++;
		}
		ft_putchar_fd(format[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (i);
}
