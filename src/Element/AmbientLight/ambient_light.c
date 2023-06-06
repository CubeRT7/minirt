/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 04:18:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

void	debug_ambient_light(void *param)
{
	struct s_ambient_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: ratio[%f]\n", __func__, c->ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__, c->rgb.r, c->rgb.g, c->rgb.b);
}

int	parse_ambient_light(void *param, char **argv)
{
	char							*remain;
	struct s_ambient_light *const	content = param;

	if (!argv || !argv[0] || !argv[1])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->ratio = ft_strtof(argv[0], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->rgb, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!(0.0 <= content->ratio && content->ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	debug_ambient_light(content);
	return (EXIT_SUCCESS);
}
