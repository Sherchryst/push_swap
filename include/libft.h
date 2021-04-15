/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:20:22 by sgah              #+#    #+#             */
/*   Updated: 2021/04/14 11:49:25 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct		s_gnl
{
	char			str[((BUFFER_SIZE > 0) ? BUFFER_SIZE + 1 : 1)];
	int				fd;
	int				i;
	int				len;
	int				l_line;
	int				tmp;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

void				ft_tabmap(char **tb, void (*f)(const char *));

long long int		ft_atoi(const char *str);

int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
int					ft_error(char *err);

char				*ft_strncat
					(char *restrict s1, const char *restrict s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strnstr
					(const char *haystack, const char *needle, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strnchr(const char *s, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strreplace(char **str, char *search, char *replace);
char				*ft_freeint(int *elem);

size_t				ft_strnlen(const char *s, size_t maxlen);

int					ft_toupper(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t count, size_t size);
void				*ft_memdel(void **ap);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);

void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstdelone(t_list *alst, void (*del)(void *));
void				ft_lstclear(t_list **alst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(void *));
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_free_tab(void **ft_tab);

int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_isxdigit(int c);

#endif
