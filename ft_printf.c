/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:57 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/20 15:18:00 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printflag(va_list *args, char flag, int *len)
{
	char	*arg;

	if (flag == 'c')
	{
		*len += 1;
		ft_putchar_fd(va_arg(*args, int), STDOUT_FILENO);
	}
	else if (flag == 's')
	{
		arg = va_arg(*args, char *);
		if (!arg)
		{
			ft_putstr_fd("(null)", STDOUT_FILENO);
			*len += 6;
		}
		else
		{
			*len += ft_strlen(arg);
			ft_putstr_fd(arg, STDOUT_FILENO);
		}
	}
	else if (flag == 'p')
	{
		arg = ft_ptrtohex(va_arg(*args, void *));
		if (!arg)
		{
			ft_putstr_fd("(nil)", STDOUT_FILENO);
			len += 5;
		}
		else
		{
			*len += ft_strlen(arg);
			*len += 2;
			ft_putstr_fd("0x", STDOUT_FILENO);
			ft_putstr_fd(arg, STDOUT_FILENO);
		}
		free(arg);
	}
	else if (flag == 'd' || flag == 'i')
	{
		arg = ft_itoa(va_arg(*args, int));
		*len += ft_strlen(arg);
		ft_putstr_fd(arg, STDOUT_FILENO);
		free(arg);
	}
	else if (flag == 'u')
	{
		arg = ft_uitoa(va_arg(*args, unsigned int));
		*len += ft_strlen(arg);
		ft_putstr_fd(arg, STDOUT_FILENO);
		free(arg);
	}
	else if (flag == 'x')
	{
		arg = ft_itohex(va_arg(*args, unsigned int), false);
		*len += ft_strlen(arg);
		ft_putstr_fd(arg, STDOUT_FILENO);
		free(arg);
	}
	else if (flag == 'X')
	{
		arg = ft_itohex(va_arg(*args, unsigned int), true);
		*len += ft_strlen(arg);
		ft_putstr_fd(arg, STDOUT_FILENO);
		free(arg);
	}
	else if (flag == '%')
	{
		*len += 1;
		ft_putchar_fd('%', STDOUT_FILENO);
	}
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
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
