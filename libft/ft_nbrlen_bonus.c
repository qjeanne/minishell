/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:04:08 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/07 19:25:18 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
