/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:57 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/14 16:19:45 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	lenght;
	va_list	args;

	args = 	va_start(args, format);
	lenght = 0;
	while (format[lenght])
	{
		if (format[lenght])
	}
	va_arg(args, int);
	va_end(args);
}
