/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:35:40 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/06 02:16:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen[2];
	size_t	dlen;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	slen[0] = ft_strlen(s1);
	slen[1] = ft_strlen(s2);
	dlen = slen[0] + slen[1];
	dst = (char *)ft_calloc(dlen + 1, sizeof(char));
	if (dst)
	{
		ft_strlcpy(dst, s1, dlen + 1);
		ft_strlcpy(dst + slen[0], s2, dlen + 1);
	}
	return (dst);
}
