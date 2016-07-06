/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 23:15:53 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 23:43:53 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"
#include "libft/libft.h"

t_list		*ft_cd(int i, t_list *list, char **foo)
{
	if (i > 2)
		ft_printf("Wrong number of arguments.\n");
	else
		ft_change_env(list, foo);
	return (list);
}

t_list		*ft_ft_env(int i, t_list *list)
{
	if (i != 1)
		ft_printf("Wrong number of arguments.\n");
	else
		ft_env(list);
	return (list);
}

t_list		*ft_ft_setenv(int i, t_list *list, char **foo)
{
	if (i != 3)
		ft_printf("Wrong number of arguments.\n");
	if (!ft_strcmp(foo[1], "PATH") || !ft_strcmp(foo[1], "HOME"))
		ft_printf("Cannot change this key.\n");
	else
		ft_setenv(list, foo[1], foo[2]);
	return (list);
}

t_list		*ft_ft_unsetenv(int i, t_list *list, char **foo)
{
	if (i != 2)
		ft_printf("Wrong number of arguments.\n");
	if (!ft_strcmp(foo[1], "PWD") || !ft_strcmp(foo[1], "OLDPWD")
		|| !ft_strcmp(foo[1], "PATH") || !ft_strcmp(foo[1], "HOME"))
		ft_printf("Cannot remove this key.\n");
	else
		ft_unsetenv(list, foo[1]);
	return (list);
}

void		ft_fork(int i, t_list *list, char **foo)
{
	foo[0] = is_path(foo[0], list);
	i = fork();
	if (i == 0)
	{
		execve(foo[0], foo, ft_list_to_tab(list));
		exit(0);
	}
	else if (i > 0)
	{
		wait(NULL);
		ft_freesplit(foo);
	}
	else
		ft_putstr("fork failed.");
}
