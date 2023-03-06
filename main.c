/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:23:47 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/03/06 22:19:50 by ichinoseyuu      ###   ########.fr       */
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
	px.pid1 = fork();
	if (px.pid1 == 0)
		chiled_1(argv, &px, envp);
	else if (px.pid1 < 0)
		exit(EXIT_FAILURE);
	px.pid2 = fork();
	if (px.pid2 == 0)
		chiled_2(argv, &px, envp);
	else if (px.pid2 < 0)
		exit(EXIT_FAILURE);
	close (px.p_fd[0]);
	close(px.p_fd[1]);
	waitpid(px.pid1, &px.status, 0);
	waitpid(px.pid2, &px.status, 0);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q pipex");
// }
