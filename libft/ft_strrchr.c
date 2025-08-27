/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:43:14 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/12 16:33:20 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	ch;

	ch = (char)c;
	p = NULL;
	while (*s)
	{
		if (*s == ch)
			p = (char *)s;
		s++;
	}
	if (*s == ch)
		p = ((char *)s);
	return (p);
}
