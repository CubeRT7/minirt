/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:03:12 by minjungk          #+#    #+#             */
/*   Updated: 2022/08/15 20:37:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef enum e_option
{
	NONE	= 0,
	FOUND	= 1 << 0,
	BLANK	= 1 << 1,
	PLUS	= 1 << 2,
	MINUS	= 1 << 3,
	ZERO	= 1 << 4,
	PREC	= 1 << 5
}			t_option;

typedef struct s_token
{
	char		*in;
	char		*out;
	char		type;
	int			width;
	int			precision;
	t_option	opt;
}				t_token;

void	ft_free_token(void *content);
t_token	*ft_make_token(void *content);
int		ft_make_tokens(t_list **head, const char *format);
int		ft_parse_token(t_token *t, va_list ap);

int		ft_printf(const char *format, ...);
#endif
