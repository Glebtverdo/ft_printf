/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_for_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:09:08 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/27 18:11:32 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

int	ft_write_zeros(t_list *start, int len, int *counter)
{
	if (start->zeros >= len && start->zeros && \
	((start->point != -1 || !ft_strchr(start->type, '-')) && \
	((!ft_strchr(&(start->type)[1], '%') || start->point == -1) || \
	start->point < start->zeros)))
	{
		if ((start->content)[0] == '-' && \
		(start->zeros > len || start->point != -1))
		{
			ft_putchar_fd('-', 1, counter);
			((char *)start->content)[0] = '0';
			if (start->point == -1)
				start->zeros--;
		}
		while (len < start->zeros)
		{
			ft_putchar_fd('0', 1, counter);
			start->zeros--;
		}
	}
	return (start->zeros);
}

int	ft_write_spaces(t_list *start, int *counter, \
int flag)
{
	if (!ft_strchr(start->type, '-'))
	{
		while (start->spaces > 0)
		{
			ft_putchar_fd(' ', 1, counter);
			start->spaces--;
		}
	}
	else if (flag == 2)
	{
		while (0 < start->spaces)
		{
			ft_putchar_fd(' ', 1, counter);
			start->spaces--;
		}
	}
	return (start->spaces);
}

void	ft_write_ox(char *content, char *type, int *counter)
{
	if ((content[0] != '0' && ft_strchr(type, '#') && \
	ft_strchr(type, 'x')) || ft_strchr(type, 'p'))
		ft_putstr_fd("0x", 1, counter, 2);
	else if (content[0] != '0' && ft_strchr(type, '#') && ft_strchr(type, 'X'))
		ft_putstr_fd("0X", 1, counter, 2);
}
