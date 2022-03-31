/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:36 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/26 00:53:50 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_main_func(long int dev, long int new_n, int size, char *new)
{
	while (dev > 0)
	{
		new[size] = new_n / dev + 48;
		new_n = new_n % dev;
		dev /= 10;
		size++;
	}
	new[size] = '\0';
	return (new);
}

char	*ft_uitoa(unsigned int n)
{
	long int		dev;
	long int		new_n;
	int				size;
	char			*new;

	dev = 1;
	size = 1;
	new_n = n;
	while (new_n >= dev * 10)
	{
		dev *= 10;
		size++;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	size = 0;
	new = ft_main_func(dev, new_n, size, new);
	return (new);
}
