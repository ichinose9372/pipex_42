/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:41:12 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/24 20:07:46 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	*make_path(char *split_arg, char **envp)
{
	char	*env_tmp;
	char	**enb_suplit;
	char	*trim;
	char	*path;
	char	*tmp;

	trim = "PATH=";
	while (*envp)
	{

		if ((ft_strncmp(*envp, trim, ft_strlen(trim))) == 0)
			break ;
		envp++;
	}
	env_tmp = ft_strtrim(*envp, trim);
	enb_suplit = ft_split(env_tmp, ':');
	trim = "/";
	tmp = ft_strjoin(trim, split_arg);
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
