/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:10:32 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 23:43:28 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"
#include "libft/libft.h"
#include <unistd.h>

void		ft_dash(t_list *list)
{
	char	*value_p;
	char	*value_op;

	value_p = ft_strdup(ft_getenv(list, "PWD"));
	value_op = ft_strdup(ft_getenv(list, "OLDPWD"));
	if (!chdir((const char*)ft_getenv(list, "OLDPWD")))
	{
		list = ft_setenv(list, "OLDPWD", value_p);
		list = ft_setenv(list, "PWD", value_op);
	}
	else
		ft_printf("Access failed.\n");
	free(value_p);
	free(value_op);
}

void		ft_tilde(t_list *list)
{
	if (!chdir((const char*)ft_getenv(list, "HOME")))
	{
		list = ft_setenv(list, "OLDPWD", ft_getenv(list, "PWD"));
		list = ft_setenv(list, "PWD", ft_getenv(list, "HOME"));
	}
	else
		ft_printf("Access failed.\n");
}

void		ft_one_dot(t_list *list)
{
	if (!chdir((const char*)ft_getenv(list, "PWD")))
		list = ft_setenv(list, "OLDPWD", ft_getenv(list, "PWD"));
	else
		ft_printf("Access failed.\n");
}

void		ft_two_dots(t_list *list)
{
	char	*value_p;
	char	*value_op;
	int		i;

	value_p = ft_getenv(list, "PWD");
	i = ft_strlen(value_p) - 1;
	while (value_p[i] != '/')
		--i;
	value_op = ft_strnew(i + 1);
	value_op[i] = '\0';
	value_op = ft_strncpy(value_op, value_p, i);
	if (!chdir((const char*)value_op))
	{
		list = ft_setenv(list, "OLDPWD", ft_getenv(list, "PWD"));
		list = ft_setenv(list, "PWD", value_op);
	}
	else
		ft_printf("Access failed.\n");
}

void		ft_other_condition(t_list *list, char **foo)
{
	if (!chdir(foo[1]))
	{
		list = ft_setenv(list, "OLDPWD", ft_getenv(list, "PWD"));
		if (foo[1][0] == '/')
			list = ft_setenv(list, "PWD", foo[1]);
		else
			list = ft_setenv(list, "PWD", ft_strjoin(ft_getenv(list, "PWD"),
				ft_strjoin("/", foo[1])));
	}
	else
		ft_printf("Access failed.\n");
}
