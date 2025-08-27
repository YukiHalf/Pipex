/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:34:54 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/09 15:38:55 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display_error(char *error_msg, bool fail)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (fail == true)
		exit(EXIT_FAILURE);
}
