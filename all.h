/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:01:51 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/26 00:35:58 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include"./libft/libft.h"
# include<stdarg.h>

int				ft_printf(char *str, ...);
int				ft_len_count(t_list *start);
int				ft_write_zeros(t_list *start, int len, \
				int *counter);
int				ft_write_spaces(t_list *start, \
				int *counter, int flag);
int				ft_write_for_write_all(t_list *start, int counter, \
				int len);
t_list			*ft_make_lst(t_list *start, char **pars_string, \
				int i, va_list par);
void			ft_free_pars_string(char **pars_string);
void			ft_write_ox(char *content, char *type, int *counter);

#endif