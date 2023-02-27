/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chiled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:56 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/27 14:46:37 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	chiled_1(char **argv, t_data *px, char **envp)
{
	px->f_fd = file_open_rd(argv[1]);
	px->s_arg = split_arg(argv[2], envp);
	close(px->p_fd[0]);
	dup2(px->f_fd, 0);
	dup2(px->p_fd[1], 1);
	px->error_num = execve(px->s_arg[0], px->s_arg, envp);
	ft_error("1\n");
}

void	chiled_2(char **argv, t_data *px, char	**envp)
{
	px->f_fd = file_open_wrt(argv[4]);
	px->s_arg = split_arg(argv[3], envp);
	close(px->p_fd[1]);
	dup2(px->p_fd[0], 0);
	dup2(px->f_fd, 1);
	close(px->f_fd);
	px->error_num = execve(px->s_arg[0], px->s_arg, envp);
	ft_error("2\n");
}

