/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/20 20:56:36 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE 4

//ne pas oublier de verifier que les coordonnees sont des entiers
//
typedef	struct		s_rooms
{
	char	*name;
	struct s_rooms	*next_tube;
	struct s_rooms	*next_room;

}					t_rooms;

typedef struct		way_pm
{
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
}					w_pm;

void				send_ants(char **way, int checkpoint_sum);
void				cons_to_room(w_pm *w, char **room_data, int i);
void				print_chained_list(w_pm *w);
void				update_journey(w_pm *w, int cmd, char *str);
int					is_cmd_tube(char *line);
void				get_ants_count(w_pm *w, char *str);
int					is_comment(char *str);
int					is_room_ok(w_pm *w, char *str, int *i);
void				get_input(w_pm *w);
void				init_w(w_pm **w);

/*
 * LIB
 */
char			*ft_cattab_str(char **tab, int i);
int				ft_onlydigit(char *str);
size_t			tablen(char **src);
int				ft_strncmp(const char *tab, const char *teub, size_t n);
char			**ft_split(char *str);
char			**ft_split_n(char *str);
int				ft_count_char(char *str, char c);
char			*ft_str3join_f(char *s1, char *s2, char *s3, int i);
char			*ft_strdup_f(char *s);
void			ft_error(void);
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
char			*ft_strjoin_f(char const *s1, char const *s2, int j);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);

#endif
