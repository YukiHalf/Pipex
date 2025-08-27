/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:02:48 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/11 19:47:38 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (src_size + 1 < dstsize)
	{
		ft_memcpy(dest, src, src_size + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dest, src, dstsize - 1);
		dest[dstsize - 1] = 0;
	}
	return (src_size);
}
