/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:02:12 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:16:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"

int	parse_double(double *res, char *str)
{
	char	*remain;

	if (res == NULL || str == NULL)
		return (EXIT_FAILURE);
	*res = ft_strtof(str, &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
