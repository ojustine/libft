/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:44:55 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/10 22:21:26 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *mem1, void *mem2, size_t size)
{
	unsigned char tmp;
	unsigned char *m1;
	unsigned char *m2;

	if (mem1 == NULL || mem2 == NULL || size == 0)
		return ;
	m1 = (unsigned char*)mem1;
	m2 = (unsigned char*)mem2;
	while (size--)
	{
		tmp = *m1;
		*m1 = *m2;
		*m2 = tmp;
		m1++;
		m2++;
	}
}
