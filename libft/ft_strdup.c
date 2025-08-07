/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:09:29 by nde-sant          #+#    #+#             */
/*   Updated: 2025/07/29 14:56:42 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	char	*cpy_str;
	int		i;

	cpy_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy_str[i] = s[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
