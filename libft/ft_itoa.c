/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:19:03 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/11 19:22:20 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long nbrlng)
{
	int	len;

	len = 0;
	if (nbrlng == 0)
		return (1);
	if (nbrlng < 0)
	{
		len++;
		nbrlng = -nbrlng;
	}
	while (nbrlng > 0)
	{
		len++;
		nbrlng = nbrlng / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = ft_nbrlen(nbr);

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
