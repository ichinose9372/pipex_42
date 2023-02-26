/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:54 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/26 19:13:34 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**split_arg;
	int		p_fd[2];
	int		pid;
	int		status;
	int		error_num;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("open error\n");
	if (pipe(p_fd) < 0)
		ft_error("pipe error\n");
	pid = fork();
		ft_error("fork error\n");
	if (pid == 0)
	{
		split_arg = ft_split(argv[1], ' ');
		path = make_path(split_arg[0], envp);
		split_arg[0] = ft_strdup(path);
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
	else
	{
		wait(&status);
		split_arg = ft_split(argv[1], ' ');
		path = make_path(split_arg[0], envp);
		split_arg[0] = ft_strdup(path);
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		error_num = execve(split_arg[0], split_arg, envp);
		printf("error_num = %d\n", error_num);
		if (error_num < 0)
		{
			perror("parent\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
