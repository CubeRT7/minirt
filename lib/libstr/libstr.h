/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:41:55 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 01:02:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTR_H
# define LIBSTR_H
# define DETECT_LEN -1
# define STRB_SUCCESS 0
# define STRB_FAIL 1
# include "libft.h"

typedef void	(*t_del)(void *p);

typedef struct s_strb
{
	t_list			*substrs;
	t_list			*last;
	int				len;
	int				err;
}	t_strb;

int			strb_init(t_strb *sb, char *str, t_del del);
int			strb_add_left(t_strb *sb, char *str, t_del del);
int			strb_add_right(t_strb *sb, char *str, t_del del);
char		*strb_finish(struct s_strb *sb);

#endif
