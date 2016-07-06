/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 17:47:47 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 23:41:09 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell1.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

t_list		*condition_1_call_fork(int i, char **foo, t_list *list)
{
	if (ft_strcmp(foo[0], "env") == 0)
	{
		if (i != 1)
			ft_printf("Wrong number of arguments.\n");
		else
			ft_env(list);
		return (list);
	}
	else if (ft_strcmp(foo[0], "setenv") == 0)
	{
		if (i != 3)
			ft_printf("Wrong number of arguments.\n");
		if (!ft_strcmp(foo[1], "PATH") || !ft_strcmp(foo[1], "HOME"))
			ft_printf("Cannot change this key.\n");
		else
			ft_setenv(list, foo[1], foo[2]);
		return (list);
	}
	return (list);
}

t_list		*call_fork(char *buf, t_list *list)
{
	pid_t	i;
	char	**foo;

	buf = ft_change_char(buf, '\t', ' ');
	foo = ft_strsplit(buf, ' ');
	i = 0;
	while (foo[i])
		i++;
	if (ft_strcmp(foo[0], "cd") == 0)
		ft_cd(i, list, foo);
	else if (ft_strcmp(foo[0], "env") == 0)
		ft_ft_env(i, list);
	else if (ft_strcmp(foo[0], "setenv") == 0)
		ft_ft_setenv(i, list, foo);
	else if (ft_strcmp(foo[0], "unsetenv") == 0)
		ft_ft_unsetenv(i, list, foo);
	else
		ft_fork(i, list, foo);
	return (list);
}

t_list		*ft_change_tab_into_list(char **env, t_list *list)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if ((path = ft_strsplit(env[i], '=')))
		{
			list = list_add_end(list, ft_list_new(path[0], path[1]));
			free(path[0]);
			free(path[1]);
			free(path);
		}
		i++;
	}
	return (list);
}

char		**ft_list_to_tab(t_list *list)
{
	char	**tmp;
	int		i;
	t_list	*mem;

	mem = list;
	i = 0;
	while (mem)
	{
		i++;
		mem = mem->next;
	}
	tmp = ft_walloc(sizeof(char *) * (i + 1));
	tmp[i] = NULL;
	i = 0;
	while (list)
	{
		tmp[i] = ft_strjoin(list->key, ft_strjoin("=", list->value));
		i++;
		list = list->next;
	}
	return (tmp);
}

int			main(int ac, char **av, char **env)
{
	char	*buf;
	t_list	*list;

	(void)ac;
	(void)av;
	ft_printf("WELCOME TO MY SHELL.\n");
	list = NULL;
	list = ft_change_tab_into_list(env, list);
	while (1)
	{
		buf = print_prompt();
		list = call_fork(buf, list);
		free(buf);
	}
	return (0);
}
