/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:04:30 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/29 17:13:25 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

static int	ft_all_clean(t_list *start, char **pars_string, va_list par)
{
	int	i;

	i = 0;
	va_end(par);
	ft_lstclear(&start);
	while (pars_string[i])
	{
		free(pars_string[i]);
		i++;
	}
	free(pars_string);
	free(start);
	return (0);
}

static int	ft_count_spaces_with_minus(t_list *start, long long int len)
{
	if (start->spaces > start->point && start->spaces > len \
	&& start->point != -1)
	{
		if (len > start->point || !start->zeros)
			start->spaces -= len;
		else
			start->spaces -= start->point;
	}
	else if (start->spaces == start->point || \
	(start->spaces < start->point && !ft_strchr(start->type, 's') \
	&& !ft_strchr(start->type, 'c')))
		start->spaces = 0;
	else if (len < start->point && start->spaces > start->point)
		start->spaces -= start->point;
	else
		start->spaces -= len;
	return (start->spaces);
}

static int	ft_count_spaces(t_list *start, long long int len)
{
	if ((ft_strchr(start->type, 's') || \
	(ft_strchr(&(start->type)[1], '%') && start->point != -1)) && \
	start->point != -2 && (start->content)[0] != '\0')
		start->spaces -= len;
	else if (ft_strchr(start->type, 's'))
		return (start->spaces);
	else if (ft_strchr(start->type, '-'))
		start->spaces = ft_count_spaces_with_minus(start, len);
	else if (start->point > len && start->spaces > start->point \
	&& !start->zeros && start->zerous_true)
		start->spaces = start->point - len;
	else if (start->point > len && start->spaces < start->point)
		start->spaces -= (start->point + len);
	else if (start->zeros && start->zeros > len)
		start->spaces -= start->zeros;
	else
		start->spaces -= len;
	if (((start->content)[0] != '0' && ft_strchr(start->type, '#') && \
	(ft_strchr(start->type, 'x') || ft_strchr(start->type, 'X'))) || \
	ft_strchr(start->type, 'p'))
		start->spaces -= 2;
	if ((start->content)[0] == '-' && (start->zeros > len || \
			start->point != -1) && start->point + 1 > len)
		start->spaces--;
	return (start->spaces);
}

static int	ft_write_all(t_list *start)
{
	long long int	len;
	int				counter;
	t_list			*buf;

	counter = 0;
	while (start)
	{
		len = ft_len_count(start);
		start->spaces = ft_count_spaces(start, len);
		start->spaces = ft_write_spaces(start, &counter, 1);
		ft_write_ox(start->content, start->type, &counter);
		start->zeros = ft_write_zeros(start, len, &counter);
		if (start->point != -2)
			counter = ft_write_for_write_all(start, counter, len);
		start->spaces = ft_write_spaces(start, &counter, 2);
		buf = start->next;
		free(start->content);
		free(start);
		start = buf;
	}
	return (counter);
}

int	ft_printf(char *str, ...)
{
	char			**pars_string;
	int				i;
	t_list			*start;
	va_list			par;
	int				counter;

	start = NULL;
	pars_string = ft_split(str, '%');
	if (!pars_string)
		return (-1);
	va_start(par, str);
	i = 0;
	while (pars_string[i] != NULL)
	{
		start = ft_make_lst(start, pars_string, i, par);
		if (ft_lstsize(start) < i + 1)
			return (ft_all_clean(start, pars_string, par));
		i++;
	}
	counter = ft_write_all(start);
	va_end(par);
	ft_free_pars_string(pars_string);
	return (counter);
}
