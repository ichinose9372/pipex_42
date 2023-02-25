/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:41:12 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/25 16:39:29 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	*make_path(char *argv, char **envp)
{
	char	*env_tmp;
	char	**enb_suplit;
	char	*trim;
	char	*path;
	char	*tmp;
	char	**split_arg;
	int		i;

	split_arg = ft_split(argv, ' ');
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
	tmp = ft_strjoin(trim, split_arg[0]);
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
