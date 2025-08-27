/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:16:48 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/12 16:30:37 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	size_d;
	size_t	size_s;

	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	if (size_d >= dstsize)
		size_d = dstsize;
	if (dstsize == size_d)
	{
		return (size_d + size_s);
	}
	if (size_s < dstsize - size_d)
	{
		ft_memcpy(dest + size_d, src, size_s + 1);
	}
	else
	{
		ft_memcpy(dest + size_d, src, dstsize - size_d - 1);
		dest[dstsize - 1] = 0;
	}
	return (size_d + size_s);
}
