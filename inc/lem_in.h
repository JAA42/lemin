/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/23 18:50:40 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE 4

typedef struct		s_way
{
	char			*name;
	int				ant;
	struct	s_way	*next;
	struct	s_way	*previous;
}					t_way;

typedef	struct		s_rooms
{
	char	*name;

	int				done;
	struct s_rooms	*next_tube;
	struct s_rooms	*next_room;

}					t_rooms;

typedef struct		s_pm
{
	t_way			*first_way;
	t_way			*last_way;
	t_rooms			*first;
	t_rooms			*last;
	int				len;
	int				cmd;
	int				ants_count;
	char			*options;
	int				fd;
	char			*way;
	char			*exit;
	char			*entrance;
	char			***rooms;
}					t_pm;

void				get_tube_data(t_pm *w, char *str, int *n);
char				*run_algo(t_pm *w);
void				print_chained_list(t_pm *w);
int					is_cmd_tube(char *line);
void				get_ants_count(t_pm *w, char *str);
int					is_comment(char *str);
int					is_room_ok(t_pm *w, char *str, int *i);
void				split_way(t_pm *w);
void				ft_error(int error_number);

/*
 * LIB
 */
char			*ft_strndup(const char *s, int n);
char			*ft_cattab_str(char **tab, int i);
int				ft_onlydigit(char *str);
size_t			tablen(char **src);
int				ft_strncmp(const char *tab, const char *teub, size_t n);
char			**ft_split(char *str);
char			**ft_split_n(char *str);
int				ft_count_char(char *str, char c);
char			*ft_str3join_f(char *s1, char *s2, char *s3, int i);
char			*ft_strdup_f(char *s);
char			*ft_str3join(char const *s1, char const *s2, char *s3);
int				get_next_line(const int fd, char **line);
char			*ft_strcat(char *dest, const char *src);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_chardup(char c);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				pos_in_str(char c, char *str);
char			*ft_strcpy(char *dest, const char *str);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
int				ft_strcmp(const char *tab, const char *tab2);
char			*ft_strdup(const char *s);
void			*ft_memalloc(size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strlen(const char *src);
void			ft_putnbr(int n);
void			*ft_memalloc_c(size_t size, int c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base, int upper);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_f(char *s1, char *s2, int j);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);

#endif
