/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 22:55:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "simulate.h"
#include "hook.h"

#define TITLE "CubeRT7"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int	main(int argc, char **argv)
{
	t_list	*objs;

	errno = 0;
	objs = NULL;
	if (parse(&objs, argc, argv))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (simulate(objs, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE))
	{
		ft_lstclear(&objs, free);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	ft_lstclear(&objs, free);
	return (EXIT_SUCCESS);
}
