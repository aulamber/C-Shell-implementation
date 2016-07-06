/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:38:41 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/18 23:49:50 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell1.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

t_list		*ft_with_one_arg(t_list *list, char **foo)
{
	if (!ft_strcmp(foo[1], "-"))
		ft_dash(list);
	else if (!ft_strcmp(foo[1], "~"))
		ft_tilde(list);
	else if (!ft_strcmp(foo[1], "."))
		ft_one_dot(list);
	else if (!ft_strcmp(foo[1], ".."))
		ft_two_dots(list);
	else
		ft_other_condition(list, foo);
	return (list);
}

char		*print_prompt(void)
{
	char	*buf;
	char	*buf2;

	ft_putstr("$> ");
	if (get_next_line(1, &buf) < 1)
		exit(0);
	buf2 = ft_strtrim(buf);
	free(buf);
	if (ft_strcmp(buf2, "exit") == 0)
		exit(0);
	return (buf2);
}

char		*ft_check_arg_true(char *str, char **tab_paths)
{
	int		i;
	char	*tmp;

	i = 0;
	if (access(str, F_OK) == 0)
		return (str);
	if (str[0] != '/')
	{
		while (tab_paths[i])
		{
			tmp = ft_strjoin(tab_paths[i], str);
			if (access(tmp, F_OK) == 0)
			{
				free(str);
				return (tmp);
			}
			else
			{
				free(tmp);
				i++;
			}
		}
	}
	ft_printf("command not found\n");
	return (NULL);
}

char		*is_path(char *str, t_list *list)
{
	char	**tab_paths;
	char	*env_path;
	int		i;

	(void)str;
	i = 0;
	env_path = ft_getenv(list, "PATH");
	tab_paths = ft_strsplit(env_path, ':');
	while (tab_paths[i])
	{
		if (tab_paths[i][ft_strlen(tab_paths[i]) - 1] != '/')
			tab_paths[i] = ft_strjoin(tab_paths[i], ft_strdup("/"));
		i++;
	}
	str = ft_check_arg_true(str, tab_paths);
	ft_freesplit(tab_paths);
	return (str);
}
