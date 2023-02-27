/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:45:33 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/27 13:54:34 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	pid_t	pid;
	int		error_num;
	int		status;
	char	**s_arg;
	int		p_fd[2];
	int		f_fd;
}	t_data;

//make_path
char	**envp_make_path(char **envp);
char	*make_path(char *split_arg, char **envp);
char	**split_arg(char *argv, char **envp);
void	pipe_init(t_data *pipex);
int		file_open_wrt(char *argv);
int		file_open_rd(char	*argv);
void	chiled_1(char **argv, t_data *px, char **envp);
void	chiled_2(char **argv, t_data *px, char **envp);
	// error
void	ft_error(char *str);
#endif
