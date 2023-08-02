/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 16:18:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern void	update(t_world *world);
extern void	render(t_world *world);
extern int	export_file(t_world *world);

int	main_loop(void *param)
{
	t_world *const	world = param;

	update(world);
	export_file(world);
	render(world);
	return (EXIT_SUCCESS);
}
