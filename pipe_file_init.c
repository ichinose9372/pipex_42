/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_file_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:50:07 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/28 14:39:33 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	file_open_rd(char	*argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("no such file or directory\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	file_open_wrt(char	*argv)
{
	int	fd;

	fd = open(argv, O_WRONLY | O_APPEND | O_TRUNC);
	if (fd < 0)
	{
		ft_putstr_fd("no such file or directory\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	pipe_init(t_data *pipex)
{
	if (pipe(pipex->p_fd) < 0)
		exit(EXIT_FAILURE);
}
