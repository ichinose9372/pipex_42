/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:45:33 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/26 20:01:09 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>

//make_path
char	*make_path(char	*split_arg, char **envp);
char	**split_arg(char *argv, char **envp);
int		pipe_init(int fd[2]);
int		file_open2(char	*argv);
int		file_open(char	*argv);


//error
void	ft_error(char *str);
#endif
