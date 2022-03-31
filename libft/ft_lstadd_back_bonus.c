/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:33 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/08 21:47:33 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*some;

	some = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{	
		some = *lst;
		some = ft_lstlast(some);
		some->next = new;
		if (new != NULL)
			new->next = NULL;
	}
}
