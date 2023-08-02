/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:18:06 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 22:50:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			++cnt;
		while (*s && *s != c)
			++s;
	}
	return (cnt);
}

static char	**free_words(char **words, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		free(words[i]);
		words[i] = 0;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	char	*p;
	char	**rtn;

	if (s == NULL)
		return (NULL);
	i = -1;
	cnt = count_words((char *)s, c);
	rtn = (char **)ft_calloc(cnt + 1, sizeof(char *));
	while (rtn && ++i < cnt)
	{
		while (*s && *s == c)
			++s;
		p = (char *)s;
		while (*s && *s != c)
			++s;
		rtn[i] = ft_substr(p, 0, s - p);
		if (rtn[i] == NULL)
			return (free_words(rtn, cnt));
	}
	return (rtn);
}
