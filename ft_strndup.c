/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:55:19 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/10 23:25:47 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*dst;
	char	*dst_begin;

	len = ft_strnlen(s1, n);
	dst = ft_strnew(len);
	dst_begin = NULL;
	if (dst)
	{
		dst_begin = dst;
		while (len--)
			*dst++ = *s1++;
		*dst = '\0';
	}
	return (dst_begin);
}
