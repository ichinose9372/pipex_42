/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:50:07 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/27 14:57:18 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	file_open_rd(char	*argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("open error\n");
	return (fd);
}

int	file_open_wrt(char	*argv)
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
	if (tmp[0] == NULL)
		return (NULL);
	return (tmp);
}

void	pipe_init(t_data *pipex)
{
	if (pipe(pipex->p_fd) < 0)
		ft_error("error pipe\n");
}
