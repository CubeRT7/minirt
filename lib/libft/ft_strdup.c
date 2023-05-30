/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:01:15 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 23:02:55 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i])
		++i;
	rtn = malloc(sizeof(char) * i + 1);
	if (rtn)
	{
		i = -1;
		while (s1[++i])
			rtn[i] = s1[i];
		rtn[i] = '\0';
	}
	return (rtn);
}
