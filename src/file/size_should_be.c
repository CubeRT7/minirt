/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_should_be.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:48:33 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:17:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"

int	size_should_be(char **argv, int size)
{
	int	i;

	if (argv == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		if (argv[i] == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	if (argv[i] != NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
