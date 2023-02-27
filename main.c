/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:23:47 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/27 13:58:49 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	px;

	if (argc < 5)
		ft_error("error\n");
	pipe_init(&px);
	if (fork() == 0)
		chiled_1(argv, &px, envp);
	if (fork() == 0)
		chiled_2(argv, &px, envp);
	close (px.p_fd[0]);
	close (px.p_fd[1]);
	waitpid(px.pid, &px.status, 0);
	waitpid(px.pid, &px.status, 0);
	return (0);
}
