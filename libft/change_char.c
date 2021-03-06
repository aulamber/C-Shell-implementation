/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 17:11:27 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/25 17:26:42 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_change_char(char *s, char c1, char c2)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c1)
			s[i] = c2;
		i++;
	}
	return (s);
}
