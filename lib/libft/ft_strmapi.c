/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:53:23 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/06 02:19:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rtn;

	if (s == NULL || f == NULL)
		return (NULL);
	rtn = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	i = -1;
	while (rtn && s[++i])
		rtn[i] = f(i, s[i]);
	return (rtn);
}
