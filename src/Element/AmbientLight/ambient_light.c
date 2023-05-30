/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 08:19:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

int	parse_ambient_light(t_list **head, char **argv)
{
	(void)head;
	(void)argv;
	return (EXIT_SUCCESS);
}

void	clear_ambient_light(void *param)
{
	t_ambient_light *const	content = param;

	(void)content;
}
