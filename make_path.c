/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:41:12 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/27 14:00:10 by ichinoseyuu      ###   ########.fr       */
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
	env_split = ft_split(*envp, ':');
	return (env_split);
}

char	*make_path(char *argv, char **envp)
{
	char	**enb_suplit;
	char	*trim;
	char	*path;
	char	*tmp;

	enb_suplit = envp_make_path(envp);
	trim = "/";
	tmp = ft_strjoin(trim, argv);
	while (*enb_suplit)
	{
		path = ft_strjoin(*enb_suplit, tmp);
		if (access(path, X_OK) == 0)
			return (path);
		enb_suplit++;
		free(path);
	}
	return (NULL);
}
