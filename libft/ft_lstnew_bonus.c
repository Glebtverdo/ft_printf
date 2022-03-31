/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:05 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/26 00:42:32 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_add_char(void *content)
{
	char			*new;

	new = malloc(sizeof(char) * 1);
	*new = (char)content;
	return (new);
}

static char	*ft_make_content(char *type, void *content)
{
	char	*newcontent;

	if (ft_strchr(type, 'c'))
		newcontent = ft_add_char(content);
	else if (ft_strchr(type, 'd') || ft_strchr(type, 'i'))
		newcontent = ft_itoa((int)content);
	else if (ft_strchr(type, 'u'))
		newcontent = ft_uitoa((int)content);
	else if (ft_strchr(type, 'p'))
		newcontent = ft_int_to_hex((unsigned long int)content);
	else if (ft_strchr(type, 'x'))
		newcontent = ft_int_to_hex((unsigned int)content);
	else if (ft_strchr(type, 'X'))
		newcontent = ft_make_big(ft_int_to_hex((unsigned int)content));
	else if (ft_strchr(type, 's') || ft_strchr(&type[1], '%'))
		newcontent = ft_strdup(content);
	else
		newcontent = NULL;
	return (newcontent);
}

t_list	*ft_lstnew(void *content, char *type)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->point = ft_point_search(type);
	new->zeros = ft_zero_search(type, new->point, &new->zerous_true);
	new->spaces = ft_spaces_search(type);
	new->type = type;
	new->content = ft_make_content(type, content);
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
