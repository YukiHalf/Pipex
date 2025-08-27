/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:22:41 by sdarius-          #+#    #+#             */
/*   Updated: 2025/07/12 15:58:11 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**fill_word(char **res, const char *s, char c);
char		**ft_split(const char *s, char c);
static int	word_count(const char *s, char c);
static char	*ft_word(const char *s, char c, size_t *i);

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	return (fill_word(res, s, c));
}

static int	word_count(const char *s, char c)
{
	size_t	i;
	size_t	c_words;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			c_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

static char	*ft_word(const char *s, char c, size_t *i)
{
	size_t	start;
	char	*word;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = (char *)malloc(*i - start + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, *i - start + 1);
	return (word);
}

char	**fill_word(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_word(s, c, &i);
			if (!res[j])
			{
				while (j > 0)
					free(res[--j]);
				free(res);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
