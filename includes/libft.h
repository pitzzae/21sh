/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:08:25 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 19:04:17 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define FT_LIBFT_H
# define BUF_SIZE 6400
# define FD_SIZE 10

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	char			select;
	int				valid;
	struct s_list	*next;
}					t_list;

typedef struct		s_lstenv
{
	char			*opt;
	char			*value;
	struct s_lstenv	*next;
}					t_lstenv;

typedef struct		s_date
{
	int				sec;
	int				min;
	int				hour;
	int				mday;
	char			*sday;
	char			*mon;
	int				year;
}					t_date;

int					get_next_line(int const fd, char **line);
char				*ft_tab_to_str(char **str);
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstnew(void const *c, size_t cz);
t_list				*ft_lstnew_free(void *c, size_t cz);
void				ft_str_replace_chr(char *str, int c, int d);
void				ft_lstprintstr(const t_list *lst);
void				ft_lstprintnbr(t_list *lst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstaddend(t_list **alst, t_list *newlst);
void				ft_lstaddend_free(t_list **alst, t_list *newlst,
					void (*del)(void *, size_t));
void				u_del(void *c, size_t d);
void				ft_lstring(t_list *lst);
t_list				*ft_lstdup(const t_list *lst, size_t ln);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstsplit(char const *s, char c);
size_t				ft_strlen(const char *s1);
size_t				ft_strocur_slash(char *str, char c);
size_t				ft_stradd_slash(char **str, char c);
size_t				ft_strocur(char *str, char c);
int					ft_strfocur(char *str, char c);
int					ft_strlocur(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t length);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_bufcpy(char *s1, const char *s2, int size);
char				*ft_strcpy_free(char *dest, char *src);
char				*ft_strncpy(char *s1, const char *s2, size_t length);
char				*ft_strdup(char *s1);
void				ft_strswap(char *s1, char *s2);
void				*ft_strcat(char *s1, const char *s2);
void				*ft_strcat_l(char *dst, const char *src, int len);
void				*ft_strncat(char *s1, const char *s2, size_t length);
size_t				ft_strlcat(char *s1, const char *s2, size_t length);
char				*ft_strchr(const char *s1, int c);
char				*ft_strrchr(const char *s1, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *s1);
int					ft_isalpha(int c1);
int					ft_isdigit(int c1);
int					ft_isalnum(int c1);
int					ft_isascii(int c1);
int					ft_isprint(int c1);
int					ft_strisprint(char *str);
int					ft_toupper(int c1);
int					ft_tolower(int c1);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_free(char *s, unsigned int t, size_t l, int f);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int fre);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_free(char *s, char c, int f);
char				**ft_strsplit_len(char const *s, char c, size_t *len);
char				*ft_itoa(long int n);
int					ft_myputchar(int c);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(long int n, int fd);
void				*ft_realloc(void *data, size_t size);
char				**ft_tab_realloc(char **data, size_t size);
void				ft_date_time(long int t, t_date *d);
t_lstenv			*ft_lst_env_new(char **env, t_lstenv **t_env, size_t pos);
void				ft_lst_to_env(t_lstenv **t_env, char ***ret, int merge);
char				*ft_lst_get_env(t_lstenv **t_env, char *opt);
char				*ft_lst_edit_env(t_lstenv **t_env, char *opt, char *value,
					int f);
char				*ft_lst_add_env(t_lstenv **t_env, char *opt, char *value);
char				*ft_lst_rm_env(t_lstenv **t_env, char *opt);
void				ft_lst_env_cpy(t_lstenv **t_env, t_lstenv **t_newenv);
char				*ft_str_replace_str(char *str, char *find, char *replace);
char				**ft_tabdup(char **tab);

#endif
