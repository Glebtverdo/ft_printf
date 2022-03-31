/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_ft_for_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:44:29 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/13 19:00:15 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

long long int	ft_check_for_ft_lines(const char *s, long long int i, char c, \
							long long int *ii)
{
	while (s[i] == '.' || s[i] == ' ' || (s[i] >= 48 && \
	s[i] <= 57) || s[i] == '-' || s[i] == '#' || s[i] == '+')
	{
		*ii += 1;
		i++;
	}
	if (s[i] == c || s[i] == 's' || s[i] == 'c' || s[i] == 'p' \
	|| s[i] == 'd' || s[i] == 'i' || s[i] == 'u' || s[i] == 'x' \
	|| s[i] == 'X' || s[i] == 'p')
	{
		*ii += 1;
		i++;
	}
	return (i);
}

long long int	ft_check_for_arr_count(const char *s, \
			long long int *i, char c, long long int arr_count)
{
	while (s[*i] == '.' || s[*i] == ' ' || (s[*i] >= 48 && \
	s[*i] <= 57) || s[*i] == '-' || s[*i] == '#' || s[*i] == '+')
		*i += 1;
	if (s[*i] == c || s[*i] == 's' || s[*i] == 'c' || s[*i] == 'p' \
	|| s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'u' || s[*i] == 'x' \
	|| s[*i] == 'X' || s[*i] == 'p')
	{
		arr_count++;
		*i += 1;
	}
	return (arr_count);
}
