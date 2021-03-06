/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:36 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/18 21:34:35 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}
