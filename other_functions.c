/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:07:33 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 18:44:57 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell1.h"

char		*ft_getenv(t_list *list, char *s)
{
	while (list)
	{
		if (!ft_strcmp(s, list->key))
		{
			return (list->value);
		}
		list = list->next;
	}
	return (NULL);
}
