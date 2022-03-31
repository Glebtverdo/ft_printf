/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:46:34 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/18 21:33:54 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	char			*type;
	int				zeros;
	int				spaces;
	int				point;
	int				minus;
	int				zerous_true;
	char			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int n);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isascii(int n);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_memcmp(void *memptr1, void *memptr2, size_t num );
int				ft_lstsize(t_list *lst);
int				ft_point_search(char *type);
int				ft_zero_search(char *type, int pointcount, int *flag);
int				ft_spaces_search(char *type);
void			*ft_calloc(size_t num, size_t size);
void			*ft_memchr(void *arr, int c, size_t n);
void			*ft_memset(void *destination, int c, size_t len);
void			*ft_bzero(void *destination, size_t len);
void			*ft_memcpy(void *destination, const void *source, size_t len);
void			*ft_memmove(void *dest, void *src, size_t len);
char			*ft_strchr(char *string, int symbol);
char			*ft_strrchr(char *string, int symbol);
char			*ft_strnstr(char *big, char *little, size_t len);
char			*ft_strdup(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_int_to_hex(unsigned long int i);
char			*ft_make_big(char *str);
char			*ft_uitoa(unsigned int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd, int *count);
void			ft_putstr_fd(char *s, int fd, \
				int *count, long long int len);
void			ft_putendl_fd(char *s, int fd);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst);
int				ft_point_search(char *type);
int				ft_zero_search(char *type, int pointcount, int *flag);
int				ft_spaces_search(char *type);
void			ft_lstiter(t_list *lst, void (*f)(void *));
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void *content, char *type);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, \
				void *(*f)(void *), void (*del)(void *));
long long int	ft_check_for_ft_lines(const char *s, long long int i, char c, \
				long long int *ii);
long long int	ft_check_for_arr_count(const char *s, \
				long long int *i, char c, long long int arr_count);

#endif