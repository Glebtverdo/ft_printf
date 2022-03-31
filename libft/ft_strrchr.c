/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:45:21 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/12 15:32:30 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(char *string, int symbol)
{
	long long int	i;
	unsigned char	s;

	i = ft_strlen(string);
	s = (unsigned char)symbol;
	while (i >= 0)
	{
		if (string[i] == s)
			return (&string[i]);
		i--;
	}
	return (NULL);
}
