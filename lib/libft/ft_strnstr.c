/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:40:40 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/06 02:22:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = -1;
	while (++i < len && haystack[i])
	{
		j = 0;
		while (i + j < len)
		{
			if (*(haystack + i + j) != *(needle + j))
				break ;
			if (*(needle + j + 1) == '\0')
				return ((char *)haystack + i);
			++j;
		}
	}
	return (NULL);
}
