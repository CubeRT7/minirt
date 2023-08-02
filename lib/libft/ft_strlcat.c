/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:51:02 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 23:02:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = 0;
	while (src[slen])
		++slen;
	dlen = 0;
	while (dst[dlen] && dlen < dstsize)
		++dlen;
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (dlen + i + 1 < dstsize && src[i])
	{
		dst[dlen + i] = src[i];
		++i;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
