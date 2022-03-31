/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_additional_funcs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:06:00 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/18 21:48:26 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_point_search(char *type)
{
	char	*start;
	int		i;

	start = ft_strchr(type, '.');
	i = -1;
	if (start)
	{
		i = -2;
		start++;
		if (ft_isdigit(*start) || !ft_strchr(type, 's'))
		{
			i = ft_atoi(start);
		}
	}
	return (i);
}

int	ft_zero_search(char *type, int pointcount, int *flag)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (type[counter])
	{
		if (ft_isdigit(type[counter]))
			break ;
		counter++;
	}
	if (type[counter] == '0' && !ft_strchr(type, 's'))
	{
		*flag = 1;
		i = ft_atoi(&type[counter]);
	}
	else
		*flag = 0;
	if (pointcount >= 0 && (ft_strchr(type, 'i') || ft_strchr(type, 'd') || \
	ft_strchr(type, 'u') || ft_strchr(type, 'x') || ft_strchr(type, 'X') || \
	ft_strchr(type, '%')))
		i = pointcount;
	return (i);
}

int	ft_spaces_search(char *type)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (type[counter])
	{
		if ((ft_isdigit(type[counter]) || type[counter] == '.') \
		&& type[counter] != '0')
			break ;
		counter++;
	}
	if (type[counter] != '\0' && type[counter] != '.')
		i = ft_atoi(&type[counter]);
	return (i);
}
