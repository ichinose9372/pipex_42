/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:54 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/24 20:22:17 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**split_arg;

	split_arg = ft_split(argv[1], ' ');
	path = make_path(split_arg[0], envp);
	split_arg[0] = ft_strdup(path);
	// printf("split_arg[0] = %s\nsplit_srg[1] = %s\nsplit_arg[2] = %s\n", split_arg[0], split_arg[1], split_arg[2]);
	execve(split_arg[0], split_arg, NULL);
	return (0);
}
