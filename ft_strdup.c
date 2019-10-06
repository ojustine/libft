/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:57:16 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/06 21:01:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;
	char *dst_begin;

	dst = ft_strnew(ft_strlen(s1));
	dst_begin = NULL;
	if (dst)
	{
		dst_begin = dst;
		while (*s1)
			*dst++ = *s1++;
		*dst = '\0';
	}
	return (dst_begin);
}
