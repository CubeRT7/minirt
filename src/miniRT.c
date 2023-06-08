/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 07:02:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "simulate.h"
#include "hook.h"

#define TITLE "CubeRT7"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static int exit_minirt(int exit_code)
{
	clear_elements();
	return (exit_code);
}

int main(int argc, char **argv)
{
	errno = 0;
	if (parse(get_elements(), argc, argv))
		return (exit_minirt(ft_error(__func__, __FILE__, __LINE__, 0)));
	if (simulate(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE))
		return (exit_minirt(ft_error(__func__, __FILE__, __LINE__, 0)));
	return (exit_minirt(EXIT_SUCCESS));
}
