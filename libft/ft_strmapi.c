/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:39:58 by nde-sant          #+#    #+#             */
/*   Updated: 2025/07/24 18:06:00 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result_str;
	int		i;

	i = 0;
	result_str = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!result_str)
		return (NULL);
	while (s[i])
	{
		result_str[i] = f(i, s[i]);
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}
