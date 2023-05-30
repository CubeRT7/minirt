/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:58:44 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 22:59:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*rtn;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		++start;
	end = ft_strrchr(s1, 0);
	while (start <= end && ft_strchr(set, *end))
		--end;
	rtn = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (rtn)
		ft_strlcpy(rtn, start, end - start + 2);
	return (rtn);
}
