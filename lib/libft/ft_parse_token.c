/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:50:52 by minjungk          #+#    #+#             */
/*   Updated: 2022/11/23 14:42:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_out(t_token *t, char *copy, int copy_len)
{
	if (t->type != 's' && copy && t->precision < copy_len)
		t->precision = copy_len;
	t->precision += 2 * (1 && (t->opt & FOUND));
	t->precision += 1 * (1 && (t->opt & (PLUS | BLANK)));
	if (t->width < t->precision)
		t->width = t->precision;
	t->out = ft_calloc(t->width + 1, sizeof(char));
	if (t->out == 0)
		return ;
	ft_memset(t->out, ' ', t->width);
	if ((t->opt & ZERO) && !(t->opt & PREC))
		t->precision = t->width;
	if (t->opt & MINUS)
		ft_memset(t->out, '0', t->precision);
	else
		ft_memset(t->out + t->width - t->precision, '0', t->precision);
	if (copy == 0)
		return ;
	if (t->type == 's')
		copy_len = t->precision;
	if (t->opt & MINUS)
		ft_memcpy(t->out + t->precision - copy_len, copy, copy_len);
	else
		ft_memcpy(t->out + t->width - copy_len, copy, copy_len);
}

static int	parse_text(t_token *t, va_list ap)
{
	char	*s;

	if (t->type == '%')
		make_out(t, "%", 1);
	else if (t->type == 'c')
	{
		make_out(t, " ", 1);
		if (t->out == 0)
			return (-1);
		if (t->opt & MINUS)
			t->out[0] = va_arg(ap, int);
		else
			t->out[t->width - 1] = va_arg(ap, int);
	}
	else if (t->type == 's')
	{
		s = va_arg(ap, char *);
		if (s == 0)
			s = "(null)";
		if ((t->opt & PREC) == 0 || t->precision >= (int)ft_strlen(s))
			t->precision = ft_strlen(s);
		if (ft_strlen(s) <= 2147483647)
			make_out(t, s, ft_strlen(s));
	}
	return (0);
}

static int	parse_number(t_token *t, char *s, char flag)
{
	if (s == 0)
		return (-1);
	if (s[0] == '-')
		t->opt |= BLANK;
	if (s[0] == '0' && (t->opt & PREC) && (t->precision < 1))
		make_out(t, "", 0);
	else if (s[0] == '-')
		make_out(t, s + 1, ft_strlen(s + 1));
	else
		make_out(t, s, ft_strlen(s));
	if (t->out)
	{
		if (s[0] == '-')
			flag = '-';
		else if (t->opt & PLUS)
			flag = '+';
		else if (t->opt & BLANK)
			flag = ' ';
		if (flag && t->opt & MINUS)
			t->out[0] = flag;
		else if (flag)
			t->out[t->width - t->precision] = flag;
	}
	free(s);
	return (0);
}

static int	parse_hex(t_token *t, char *s)
{
	int	len;

	if (s == 0)
		return (-1);
	len = ft_strlen(s);
	if (s[0] == '0' && (t->type != 'p'))
	{
		t->opt &= ~FOUND;
		if ((t->opt & PREC) && (t->precision < 1))
			len = 0;
	}
	make_out(t, s, len);
	if (t->out)
	{
		if ((t->opt & FOUND) && (t->opt & MINUS))
			ft_memcpy(t->out, "0x", 2);
		if ((t->opt & FOUND) && !(t->opt & MINUS))
			ft_memcpy(t->out + t->width - t->precision, "0x", 2);
		len = -1;
		while (s[0] != '0' && t->type == 'X' && t->out[++len])
			t->out[len] = ft_toupper(t->out[len]);
	}
	free(s);
	return (0);
}

int	ft_parse_token(t_token *t, va_list ap)
{
	const char	*dec = "0123456789";
	const char	*hex = "0123456789abcdef";

	if (t == 0)
		return (-1);
	if (t->type == '%' || t->type == 'c' || t->type == 's')
		return (parse_text(t, ap));
	else if (t->type == 'd' || t->type == 'i')
		return (parse_number(t, ft_itoa(va_arg(ap, int)), 0));
	else if (t->type == 'u')
		return (parse_number(t, ft_utoa(va_arg(ap, unsigned int), dec), 0));
	else if (t->type == 'x' || t->type == 'X')
		return (parse_hex(t, ft_utoa(va_arg(ap, unsigned int), hex)));
	else if (t->type == 'p')
		return (parse_hex(t, ft_utoa(va_arg(ap, unsigned long), hex)));
	else
		t->out = ft_strdup(t->in);
	if (t->out == 0)
		return (-1);
	return (0);
}
