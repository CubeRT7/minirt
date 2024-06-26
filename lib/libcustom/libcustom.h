/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcustom.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:36:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/13 00:18:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUSTOM_H
# define LIBCUSTOM_H
# include "libft.h"
# include <stdio.h>

# ifdef __DEBUG__
#  define DEBUG 1
# else
#  define DEBUG 0
# endif

extern char		*ft_ftoa(float f, int digit);
extern int		ft_error(const char *func, char *file, int line, int sub_errno);
extern float	ft_strtof(const char *nptr, char **endptr);
extern void		ft_strarr_free(char **argv);

#endif
