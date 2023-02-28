/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chiled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:56 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/28 12:25:24 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	chiled_1(char **argv, t_data *px, char **envp)
{
	px->f_fd = file_open_rd(argv[1]);
	px->split_arg = split_arg(argv[2], envp);
	if (px->split_arg == NULL)
		ft_error("error\n");
	close(px->p_fd[0]);
	dup2(px->f_fd, 0);
	dup2(px->p_fd[1], 1);
	px->error_num = execve(px->split_arg[0], px->split_arg, envp);
}

void	chiled_2(char **argv, t_data *px, char	**envp)
{
	px->f_fd = file_open_wrt(argv[4]);
	px->split_arg = split_arg(argv[3], envp);
	if (px->split_arg == NULL)
		ft_error("error\n");
	close(px->p_fd[1]);
	dup2(px->p_fd[0], 0);
	dup2(px->f_fd, 1);
	close(px->f_fd);
	px->error_num = execve(px->split_arg[0], px->split_arg, envp);
}

