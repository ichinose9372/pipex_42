/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:14:17 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/25 17:09:03 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**split_arg;
	int		fd;
	int		p_fd[2];
	int		pid;
	int		error_num;
	char	*path;
	int		status;


	split_arg = malloc(sizeof(char *) * 3);
	if (split_arg == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	split_arg[0] = NULL;
	split_arg[1] = NULL;
	split_arg[2] = NULL;

	if (pipe(p_fd) < 0)
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
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		split_arg[0] = make_path(argv[2], envp);
		split_arg[1] = argv[1];
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		close(p_fd[1]);
		error_num = execve(split_arg[0], split_arg, envp);
		if (error_num < 0)
		{
			perror("chiled\n");
			exit(EXIT_FAILURE);
		}
		close(p_fd[1]);
	}
	else if (pid > 0)
	{
		wait(&status);
		split_arg[0] = make_path(argv[3], envp);
		split_arg[1] = "-l";
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		error_num = execve(split_arg[0], split_arg, envp);
		if (error_num < 0)
		{
			perror("parent\n");
			exit(EXIT_FAILURE);
		}
	}


	return (0);
}
