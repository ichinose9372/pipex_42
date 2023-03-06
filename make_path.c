/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:41:12 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/03/06 15:15:44 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	**envp_make_path(char **envp)
{
	char	*serch;
	char	*trim_env;
	char	**env_split;

	serch = "PATH=";
	while (*envp)
	{
		if ((ft_strncmp(*envp, serch, ft_strlen(serch))) == 0)
			break ;
		envp++;
	}
	trim_env = ft_strtrim(*envp, serch);
	env_split = ft_split(trim_env, ':');
	if (env_split == NULL)
		return (NULL);
	free(trim_env);
	return (env_split);
}

char	*make_path(char *argv, char **envp)
{
	char	**env_split;
	char	*trim;
	char	*path;
	char	*tmp;
	int		i;

	env_split = envp_make_path(envp);
	if (env_split == NULL)
		return (NULL);
	trim = "/";
	tmp = ft_strjoin(trim, argv);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (env_split[i])
	{
		path = ft_strjoin(env_split[i], tmp);
		if (path == NULL)
			return (NULL);
		if (access(path, X_OK) == 0)
		{
			free_all(env_split);
			free(tmp);
			return (path);
		}
		free(env_split[i]);
		i++;
		env_split++;
		free(path);
	}
	command_not_found(argv);
	return (NULL);
}

char	**split_arg(char *argv, char **envp)
{
	char	**tmp;

	if (argv == NULL || *argv == '\0')
		return (NULL);
	tmp = ft_split(argv, ' ');
	if (tmp == NULL)
		return (NULL);
	tmp[0] = make_path(tmp[0], envp);
	if (tmp[0] == NULL)
		return (NULL);
	return (tmp);
}
