/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:49 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/13 19:00:41 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	*free_all(char **new, long long int max)
{
	long long int	i;

	i = 0;
	free(new[max]);
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (NULL);
}	

static long long int	arr_count_counter(const char *s, \
			long long int i, char c)
{
	long long int	arr_count;

	if (s[i] != c && s[i])
		arr_count = 1;
	else
		arr_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			if (s[i] == c)
			{
				arr_count++;
				i++;
			}
			else
				arr_count = ft_check_for_arr_count(s, &i, c, arr_count);
			if (s[i] != c && s[i] != '\0')
				arr_count++;
		}
		if (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (arr_count);
}

static long long int	ft_lines(const char *s, long long int i, char c, \
							long long int *ii)
{
	if (s[i] == c)
	{
		i++;
		*ii += 1;
		if (s[i] == c)
		{
			*ii += 1;
			i++;
		}
		else
			i = ft_check_for_ft_lines(s, i, c, ii);
	}
	else
	{
		while (s[i] != c && s[i] != '\0' )
		{
			i++;
			*ii += 1;
		}
	}
	return (i);
}

static char	**ft_main_logic(long long int arr_count, \
			const char *s, char c, char **new)
{
	long long int	ii;
	long long int	iii;
	long long int	i;

	ii = 0;
	iii = 0;
	i = 0;
	while (arr_count >= iii)
	{
		ii = 0;
		i = ft_lines(s, i, c, &ii);
		new[iii] = malloc(sizeof(char) * (ii + 1));
		if (new[iii] == NULL)
			return (free_all(new, arr_count));
		ft_strlcpy(new[iii], &s[i - ii], ii + 1);
		iii++;
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	long long int	i;
	long long int	arr_count;
	char			**new;

	if (s == NULL)
		return (NULL);
	i = 0;
	arr_count = arr_count_counter(s, i, c);
	new = (char **)malloc(sizeof(char *) * (arr_count + 1));
	if (new == NULL)
		return (NULL);
	new[arr_count--] = NULL;
	new = ft_main_logic(arr_count, s, c, new);
	return (new);
}
