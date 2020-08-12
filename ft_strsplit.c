/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:42:28 by ojustine          #+#    #+#             */
/*   Updated: 2019/09/08 23:03:20 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static size_t	words_count(char const *s, char c)
//{
//	size_t	words;
//
//	words = 0;
//	if (!s || *s == '\0')
//		return (0);
//	while (*s)
//	{
//		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
//			words++;
//		s++;
//	}
//	return (words);
//}
//
//static size_t	next_len(char const *s, char c)
//{
//	size_t	len;
//
//	len = 0;
//	if (!s)
//		return (0);
//	while (*s)
//	{
//		if (*s == c)
//			s++;
//		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
//		{
//			len++;
//			break ;
//		}
//		if (*s != c)
//			len++;
//		s++;
//	}
//	return (len);
//}
//
//static char		**free_tab(char **split)
//{
//	while (*split)
//	{
//		free(*split);
//		split++;
//	}
//	free(split);
//	return (NULL);
//}
//
//char			**ft_strsplit(char const *s, char c)
//{
//	char	**split;
//	char	**ret;
//	size_t	len;
//
//	if (!s || !(split = malloc(sizeof(char*) * words_count(s, c) + 1)))
//		return (NULL);
//	ret = split;
//	while (*s)
//	{
//		if (*s != c && *s != '\0')
//		{
//			len = next_len(s, c);
//			if ((*split = ft_strnew(len)) == NULL)
//				return (free_tab(ret));
//			ft_memcpy(*split, s, len);
//			s += (len - 1);
//			split++;
//		}
//		s++;
//	}
//	*split = NULL;
//	return (ret);
//}

static size_t	ft_count_words(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char		*ft_get_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char		**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}