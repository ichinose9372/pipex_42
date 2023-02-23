/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:02:14 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/23 17:01:54 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

extern char	**environ;


int	main(void)
{
	char	**env;
	char	**str;
	char	*tmp;
	char	*path;
	char	*cmd;

	env = environ;
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	tmp = "PATH=";
	*env = ft_strtrim(*env, tmp);
	str = ft_split(*env, ':');
	cmd = "/ls";
	while (*str)
	{
		path = ft_strjoin(*str, cmd);
		if (access(path, X_OK) == 0)
			break ;
		str++;
		free(path);
	}
	printf("%s\n", path);
	printf("aaaa\n");
	return (0);
}
