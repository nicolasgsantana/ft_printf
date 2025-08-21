/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:57 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/21 13:09:13 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printflag(va_list *args, char flag, int *len)
{
	if (flag == 'c')
		*len += printfchr(args);
	else if (flag == 's')
		*len += printfstr(args);
	else if (flag == 'p')
		*len += printfptr(args);
	else if (flag == 'd' || flag == 'i')
		*len += printfint(args, false);
	else if (flag == 'u')
		*len += printfint(args, true);
	else if (flag == 'x')
		*len += printfhex(args, false);
	else if (flag == 'X')
		*len += printfhex(args, true);
	else if (flag == '%')
	{
		*len += 1;
		ft_putchar_fd('%', STDOUT_FILENO);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printflag(&args, format[++i], &len);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], STDOUT_FILENO);
			len++;
		}
	}
	va_end(args);
	return (len);
}
