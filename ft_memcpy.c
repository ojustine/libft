/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:26:52 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/06 19:05:09 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ret;

	ret = dst;
	if ((unsigned char*)dst == NULL && (unsigned char*)src == NULL)
		return (NULL);
	while (n--)
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	return (ret);
}
