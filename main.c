/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:23:47 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/03/10 15:44:02 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_data	px;

	if (argc != 5)
	{
		ft_putendl_fd("error", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	pipe_init(&px);
	px.pid[0] = fork();
	if (px.pid[0] == 0)
		chiled_1(argv, &px, envp);
	else if (px.pid[0] < 0)
		exit(EXIT_FAILURE);
	px.pid[1] = fork();
	if (px.pid[1] == 0)
		chiled_2(argv, &px, envp);
	else if (px.pid[1] < 0)
		exit(EXIT_FAILURE);
	close(px.p_fd[0]);
	close(px.p_fd[1]);
	waitpid(px.pid[0], &px.status, 0);
	waitpid(px.pid[1], &px.status, 0);
	return (EXIT_SUCCESS);
}

	__attribute__((destructor)) static void destructor()
	{
		system("leaks -q pipex");
	}
