/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:54 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/24 20:58:25 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**split_arg;
	int		fd[2];
	int		pid;
	int		status;
	int		error_num;

	split_arg = ft_split(argv[1], ' ');
	path = make_path(split_arg[0], envp);
	split_arg[0] = ft_strdup(path);
	// printf("split_arg[0] = %s\nsplit_srg[1] = %s\nsplit_arg[2] = %s\n", split_arg[0], split_arg[1], split_arg[2]);
	if (pipe(fd) < 0)
	{
		perror("pipe\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		error_num = execve(split_arg[0], split_arg, envp);
		if (error_num < 0)
		{
			perror("parent\n");
			exit(EXIT_FAILURE);
		}
		close(fd[1]);
	}
	else
	{
		wait(&status);
		split_arg = ft_split(argv[2], ' ');
		path = make_path(split_arg[0], envp);
		split_arg[0] = ft_strdup(path);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		error_num = execve(split_arg[0], split_arg, envp);
		if (error_num < 0)
		{
			perror("parent\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
