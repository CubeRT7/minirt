/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:08:26 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/06 23:16:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*		libc - ctype	*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*		libc - strings	*/
void	ft_bzero(void *s, size_t n);

/*		libc - string	*/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*		libc - stdlib	*/
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

/*		part2	*/
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*		part2	-	file descriptor	*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*		bonus - list	*/
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
// get_next_line
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

/* ************************************************************************** */
// ft_printf
/* ************************************************************************** */

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

char	*ft_utoa(unsigned long n, const char *base);
void	ft_free_token(void *content);
t_token	*ft_make_token(void *content);
int		ft_make_tokens(t_list **head, const char *format);
int		ft_parse_token(t_token *t, va_list ap);

int		ft_printf(const char *format, ...);
#endif
