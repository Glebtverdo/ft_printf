/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_additional_funcs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:26:22 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/29 17:06:16 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

int	ft_len_count(t_list *start)
{
	int	len;

	len = ft_strlen((char *)start->content);
	if ((start->content)[0] == '\0' && start->spaces)
		len++;
	if (len > start->point && start->point != -1 && \
	ft_strchr(start->type, 's'))
		len = start->point;
	if (len == 1 && (start->content)[0] == '0'\
	&& start->point == 0)
		len = 0;
	if (ft_strchr(start->type, 'p') && len == 3 && \
	(start->content)[2] == '0' && start->point == 0)
		len--;
	return (len);
}

int	ft_write_for_write_all(t_list *start, int counter, \
int len)
{
	if (ft_strchr(start->type, '+') && \
	(start->content)[0] != '-')
		ft_putchar_fd('+', 1, &counter);
	else if (ft_strchr(start->type, ' ') && \
	(start->content)[0] != '-')
		ft_putchar_fd(' ', 1, &counter);
	if (ft_strchr(start->type, 'c'))
		ft_putchar_fd(*(start->content), 1, &counter);
	else
		ft_putstr_fd(start->content, 1, &counter, len);
	return (counter);
}

t_list	*ft_make_lst(t_list *start, char **pars_string, int i, va_list par)
{
	if (pars_string[i][0] == '%' && ft_strchr(&pars_string[i][1], '%'))
		ft_lstadd_back(&start, ft_lstnew(("%\0"), pars_string[i]));
	else if (pars_string[i][0] == '%')
		ft_lstadd_back(&start, ft_lstnew(va_arg(par, void *) \
		, &pars_string[i][1]));
	else if (pars_string[i][0] != '%')
		ft_lstadd_back(&start, ft_lstnew(pars_string[i], "s"));
	return (start);
}

void	ft_free_pars_string(char **pars_string)
{
	long long int	i;

	i = 0;
	while (pars_string[i])
	{
		free(pars_string[i]);
		i++;
	}
	free(pars_string);
}
