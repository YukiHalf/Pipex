/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:54:15 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/09 19:30:10 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dsttmp;
	unsigned char	*srctmp;

	if (src == (void *)0 && dst == (void *)0)
		return (dst);
	dsttmp = (unsigned char *)dst;
	srctmp = (unsigned char *)src;
	while (n > 0)
	{
		*dsttmp = *srctmp;
		dsttmp++;
		srctmp++;
		n--;
	}
	return (dst);
}
