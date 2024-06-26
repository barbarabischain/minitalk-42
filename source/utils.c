/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:45 by babischa          #+#    #+#             */
/*   Updated: 2024/06/20 16:45:49 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			result = result * 10 + (*nptr++ - '0');
		else
			return (ERROR);
	}
	return (result);
}
