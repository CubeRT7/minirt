/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_range_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:48:33 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:17:33 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"

int	size_range_in(char **argv, int min, int max)
{
	int	i;

	if (argv == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < min)
	{
		if (argv[i] == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	while (i < max)
	{
		if (argv[i] == NULL)
			return (EXIT_SUCCESS);
		i++;
	}
	if (i == max && argv[i] != NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
