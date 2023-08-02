/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:59:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 15:55:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H
# include "../element.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

enum e_vector_scope
{
	UnitScope,
	AllScope
};

struct s_parse_info
{
	const char	*type;
	size_t		size;
	int			(*parse)(void *, char **);
};

struct s_parse_dto
{
	t_vector3	coordinate;
	t_vector3	axis;
	t_rgb		rgb;
	double		ratio;
	double		fov;
	double		diameter;
	double		height;
	double		mapid;
};

extern t_color	rgb_to_color(t_rgb rgb);

extern int		size_should_be(char **argv, int size);
extern int		size_range_in(char **argv, int min, int max);

extern int		parse_rgb(struct s_rgb *rgb, char *curr);
extern int		parse_double(double *res, char *str);
extern int		parse_vector3(t_vector3 *vector, char *curr, int scope);

extern void		serialize_rgb(int fd, t_color c);
extern int		serialize_vector3(int fd, t_vector3 v);
extern int		serialize_double(int fd, double v);

#endif
