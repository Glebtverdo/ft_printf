/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:45 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/18 21:37:17 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd, int *count, long long int len)
{
	long long int	i;

	i = 0;
	if (s)
	{
		while (i < len && s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd, count);
			i++;
		}	
	}
}
