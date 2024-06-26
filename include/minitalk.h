/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:39:14 by babischa          #+#    #+#             */
/*   Updated: 2024/06/24 18:00:46 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR	1
# define TRUE 1
# define FALSE 0

int		ft_atoi(const char *nptr);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);

typedef struct s_message
{
	unsigned char	c;
	int				i;
}t_message;

#endif
