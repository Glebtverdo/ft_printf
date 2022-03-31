/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:56 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/08 21:58:13 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*buf;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			buf = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = buf;
		}
	}
}
