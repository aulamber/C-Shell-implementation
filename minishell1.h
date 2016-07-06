/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 17:36:04 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/20 17:57:24 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
# define MINISHELL1_H

# include <stddef.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char				**change_path(char *old, char *newp, char **env);
t_list				*ft_change_tab_into_list(char **env, t_list *list);
void				ft_error(char *s);
void				*ft_walloc(int size);
t_list				*ft_list_new(char *key, char *value);
t_list				*list_add_end(t_list *list, t_list *newl);
void				list_destroy(t_list *list);
t_list				*ft_unsetenv(t_list *list, char *key);
t_list				*ft_setenv(t_list *list, char *key, char *value);
void				ft_env(t_list *list);
char				**ft_list_to_tab(t_list *list);
char				*ft_getenv(t_list *list, char *s);
t_list				*ft_change_env(t_list *list, char **foo);
char				*find_path_value(t_list *list, char *key);
t_list				*ft_with_one_arg(t_list *list, char **foo);
t_list				*ft_cd(int i, t_list *list, char **foo);
t_list				*ft_ft_env(int i, t_list *list);
t_list				*ft_ft_setenv(int i, t_list *list, char **foo);
t_list				*ft_ft_unsetenv(int i, t_list *list, char **foo);
void				ft_fork(int i, t_list *list, char **foo);
char				*is_path(char *str, t_list *list);
void				ft_dash(t_list *list);
void				ft_tilde(t_list *list);
void				ft_one_dot(t_list *list);
void				ft_two_dots(t_list *list);
void				ft_other_condition(t_list *list, char **foo);
char				*print_prompt(void);
t_list				*ft_unsetenv_2(t_list *list, t_list *tmp);

#endif
