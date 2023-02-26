/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:50:07 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:16 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	file_open(char	*argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("open error\n");
	return (fd);
}

int	file_open2(char	*argv)
{
	int	fd;

	fd = open(argv, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		ft_error("open error\n");
	return (fd);
}

char	**split_arg(char *argv, char **envp)
{
	char	**tmp;

	tmp = ft_split(argv, ' ');
	if (tmp == NULL)
	{
		ft_error("tmp error\n");
		return (NULL);
	}
	tmp[0] = make_path(tmp[0], envp);
	return (tmp);
}

int	pipe_init(int fd[2])
{
	int	pid;

	if (pipe(fd) < 0)
		ft_error("error pipe\n");
	pid = fork();
	if (pid < 0)
		ft_error("error fork\n");
	return (pid);
}
