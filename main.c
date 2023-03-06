/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:23:47 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/03/06 19:05:57 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	px;

	if (argc != 5)
	{
		ft_putendl_fd("error", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	pipe_init(&px);
	if (fork() == 0)
		chiled_1(argv, &px, envp);
	if (fork() == 0)
		chiled_2(argv, &px, envp);
	close (px.p_fd[0]);
	close(px.p_fd[1]);
	wait(&px.status);
	wait(&px.status);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q pipex");
// }
