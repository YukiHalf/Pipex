/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:06:55 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/12 16:26:05 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsttmp;
	char	*srctmp;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dsttmp = (char *)dst;
	srctmp = (char *)src;
	if (dsttmp > srctmp)
	{
		while (len-- > 0)
			dsttmp[len] = srctmp[len];
	}
	else
	{
		while (i < len)
		{
			dsttmp[i] = srctmp[i];
			i++;
		}
	}
	return (dst);
}
