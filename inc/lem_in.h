/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:07:31 by adhondt           #+#    #+#             */
/*   Updated: 2018/06/14 13:25:19 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


char			*ft_strcat(char *dest, const char *src);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_chardup(char c);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
int				pos_in_str(char c, char *str);
char			*ft_strcpy(char *dest, const char *str);
void			ft_putstr(char const *s);
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

#endif
