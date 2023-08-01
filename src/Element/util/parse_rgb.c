/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:30:08 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/01 19:23:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_util.h"

static char	*next_rgb(int *buf, char *curr)
{
	if (curr == NULL || ft_isdigit(curr[0]) == 0)
		return (NULL);
	*buf = ft_atoi(curr);
	if (!(0 <= *buf && *buf <= 255))
		return (NULL);
	while (ft_isdigit(curr[0]))
		++curr;
	if (curr[0] != '\0' && ft_strchr(",\r\n", curr[0]) == NULL)
		return (NULL);
	return (curr);
}

int	parse_rgb(struct s_rgb *rgb, char *curr)
{
	curr = next_rgb(&rgb->r, curr);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->g, curr + 1);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->b, curr + 1);
	if (curr == NULL || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}
