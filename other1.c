/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:34:53 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 23:35:12 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell1.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

t_list		*list_add_end(t_list *list, t_list *newl)
{
	t_list	*tmp;

	tmp = list;
	if (!list)
		return (newl);
	while (list && list->next)
		list = list->next;
	list->next = newl;
	newl->prev = list;
	return (tmp);
}

t_list		*ft_list_new(char *key, char *value)
{
	t_list	*tmp;

	tmp = ft_walloc(sizeof(t_list));
	tmp->key = ft_strdup(key);
	tmp->value = ft_strdup(value);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void		*ft_walloc(int size)
{
	void	*tmp;

	if ((tmp = malloc(size)))
	{
		ft_bzero(tmp, size);
		return (tmp);
	}
	else
	{
		ft_error("Malloc failed. Exiting.");
		return (NULL);
	}
}

void		ft_error(char *s)
{
	ft_putendl("-------------------------------");
	ft_putendl("");
	ft_putendl(s);
	ft_putendl("");
	ft_putendl("-------------------------------");
	exit(-1);
}

t_list		*ft_change_env(t_list *list, char **foo)
{
	if (!foo[1])
	{
		list = ft_setenv(list, "OLDPWD", ft_getenv(list, "PWD"));
		list = ft_setenv(list, "PWD", ft_getenv(list, "HOME"));
		chdir((const char*)ft_getenv(list, "PWD"));
	}
	else if (foo[1] && !foo[2])
		ft_with_one_arg(list, foo);
	else if (foo[1] && foo[2])
	{
		ft_printf("Too many arguments.\n");
		return (NULL);
	}
	return (list);
}
