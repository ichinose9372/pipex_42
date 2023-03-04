/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chiled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:56 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/03/04 11:50:15 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	chiled_1(char **argv, t_data *px, char **envp)
{
	char	buf;

	px->f_fd = file_open_rd(argv[1]);
	if (argv[2] && argv[2][0] != '\0')
	{
		px->split_arg = split_arg(argv[2], envp);
		if (px->split_arg == NULL)
			exit(EXIT_FAILURE);
		close(px->p_fd[0]);
		dup2(px->f_fd, 0);
		dup2(px->p_fd[1], 1);
		px->error_num = execve(px->split_arg[0], px->split_arg, envp);
		perror("exec");
	}
	else
	{
		while (read(px->f_fd, &buf, 1) > 0)
			write(px->p_fd[1], &buf, 1);
		close(px->f_fd);
		close(px->p_fd[1]);
		exit(EXIT_SUCCESS);
	}
}

void	chiled_2(char **argv, t_data *px, char	**envp)
{
	char	buf;

	px->f_fd = file_open_wrt(argv[4]);
	if (argv[3] && argv[3][0] != '\0')
	{
		px->split_arg = split_arg(argv[3], envp);
		if (px->split_arg == NULL)
			exit(EXIT_FAILURE);
		close(px->p_fd[1]);
		dup2(px->p_fd[0], 0);
		dup2(px->f_fd, 1);
		close(px->f_fd);
		px->error_num = execve(px->split_arg[0], px->split_arg, envp);
		perror("exec");
	}
	else
	{
		close(px->p_fd[1]);
		while (read(px->p_fd[0], &buf, 1) > 0)
			write(px->f_fd, &buf, 1);
		close(px->f_fd);
		close(px->p_fd[0]);
		exit(EXIT_SUCCESS);
	}
}
