/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:14:17 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/26 20:00:08 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**s_arg;
	int		fd;
	int		p_fd[2];
	int		pid;
	int		error_num;
	int		status;

	pid = pipe_init(p_fd);
	if (pid == 0)
	{
		fd = file_open(argv[1]);
		s_arg = split_arg(argv[2], envp);
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		close(p_fd[1]);
		error_num = execve(s_arg[0], s_arg, envp);
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
		s_arg = split_arg(argv[3], envp);
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		fd = file_open2(argv[4]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		error_num = execve(s_arg[0], s_arg, envp);
		if (error_num < 0)
			ft_error("parent error\n");
	}
	else
		ft_error("error fork\n");
	return (0);
}
