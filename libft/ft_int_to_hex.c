/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:54:59 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/14 01:02:13 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_int_to_hex(int n)
// {
// 	long long int i;
// }

static char	*ft_main_func(unsigned long long int dev, unsigned long int new_n, \
long long int size, char *new)
{
	while (dev > 0)
	{
		if (new_n / dev < 10)
			new[size] = new_n / dev + 48;
		else
			new[size] = new_n / dev + 87;
		new_n = new_n % dev;
		dev /= 16;
		size++;
	}
	new[size] = '\0';
	return (new);
}

char	*ft_int_to_hex(unsigned long int n)
{
	unsigned long long int		dev;
	unsigned long int			new_n;
	long long int				size;
	char						*new;

	dev = 1;
	size = 1;
	new_n = n;
	dev = 1;
	while (new_n >= dev * 16)
	{
		if (size == 16)
			break ;
		dev *= 16;
		size++;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	size = 0;
	new = ft_main_func(dev, new_n, size, new);
	return (new);
}
