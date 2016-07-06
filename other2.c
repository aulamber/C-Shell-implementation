/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:35:19 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/19 00:00:24 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell1.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void		ft_env(t_list *list)
{
	while (list)
	{
		ft_printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
}

t_list		*ft_setenv(t_list *list, char *key, char *value)
{
	t_list	*tmp;

	tmp = list;
	while (list && list->next)
	{
		if (!ft_strcmp(key, list->key))
		{
			free(list->value);
			list->value = ft_strdup(value);
			return (tmp);
		}
		list = list->next;
	}
	list = list_add_end(list, ft_list_new(key, value));
	return (list);
}

t_list		*ft_unsetenv_2(t_list *list, t_list *tmp)
{
	if (list == tmp)
	{
		tmp = list->next;
		if (list->next)
			list->next->prev = NULL;
		list_destroy(list);
		return (tmp);
	}
	list->prev->next = list->next;
	if (list->next)
		list->next->prev = list->prev;
	list_destroy(list);
	return (tmp);
}

t_list		*ft_unsetenv(t_list *list, char *key)
{
	t_list	*tmp;

	if ((tmp = list))
	{
		while (list)
		{
			if (!ft_strcmp(key, list->key))
				ft_unsetenv_2(list, tmp);
			list = list->next;
		}
	}
	return (NULL);
}

void		list_destroy(t_list *list)
{
	if (list)
	{
		free(list->key);
		free(list->value);
		free(list);
	}
}
