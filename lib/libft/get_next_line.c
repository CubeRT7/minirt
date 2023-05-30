/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 05:46:00 by minjungk          #+#    #+#             */
/*   Updated: 2022/11/23 14:41:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *dst, char *src, size_t slen, int *err)
{
	char	*tmp;
	size_t	dlen;

	if (src == 0 || src[0] == 0)
		return (dst);
	dlen = 0;
	if (dst)
		dlen = ft_strlen(dst);
	if (slen > ft_strlen(src))
		slen = ft_strlen(src);
	tmp = (char *)ft_calloc(dlen + slen + 1, sizeof(char));
	if (tmp == 0)
	{
		*err = 1;
		free(dst);
		return (0);
	}
	ft_memcpy(tmp, dst, dlen);
	ft_memcpy(tmp + dlen, src, slen);
	free(dst);
	ft_memmove(src, src + slen, BUFFER_SIZE - slen);
	ft_memset(src + BUFFER_SIZE - slen, 0, slen);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	read_buf[BUFFER_SIZE + 1];
	ssize_t		read_len;
	ssize_t		idx;
	char		*rtn;
	int			err;

	err = 0;
	rtn = 0;
	idx = -1;
	read_len = BUFFER_SIZE;
	while (0 <= fd)
	{
		if (++idx == BUFFER_SIZE)
		{
			rtn = join(rtn, read_buf, ft_strlen(read_buf), &err);
			read_len = read(fd, read_buf, BUFFER_SIZE);
			if (read_len < 0 || err)
				break ;
			idx = 0;
		}
		if (idx == read_len || read_buf[idx] == '\n')
			return (join(rtn, read_buf, idx + 1, &err));
	}
	free(rtn);
	return (0);
}
