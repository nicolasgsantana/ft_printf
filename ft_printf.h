/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:31:25 by nde-sant          #+#    #+#             */
/*   Updated: 2025/08/21 13:10:08 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

int		ft_printf(const char *format, ...);
char	*ft_itohex(uintptr_t n, bool uppercase);
char	*ft_ptrtohex(void *ptr);
char	*ft_uitoa(unsigned int n);
int		printfchr(va_list *args);
int		printfstr(va_list *args);
int		printfint(va_list *args, bool uint);
int		printfhex(va_list *args, bool uppercase);
int		printfptr(va_list *args);

#endif
