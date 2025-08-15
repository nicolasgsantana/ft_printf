/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:57 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/15 09:15:36 by nicolas          ###   ########.fr       */
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
		if (format[i++] == '%')
			if (format[i++] == 's')
				ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
		ft_putchar_fd(format[i++], STDOUT_FILENO);
	}
	va_end(args);
	return (i);
}
