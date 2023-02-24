/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:54 by ichinoseyuu       #+#    #+#             */
/*   Updated: 2023/02/24 20:15:37 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	ft_all_free(char **str)
{
	size_t	i;

	i = 0;
	while (**str)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

	int main(int argc, char **argv, char **envp)
{
	int		i;
	char	**cmd1;
	char	*path;
	char	*tmp;
	char	**split_arg;

	cmd1 = malloc(sizeof(char *) * argc);
	if (cmd1 == NULL)
		return (0);
	i = 0;
	while (argv[i + 1])
	{
		cmd1[i] = ft_strdup(argv[i + 1]);
		printf("cmd1[%d] = %s\n", i, cmd1[i]);
		i++;
	}
	split_arg = ft_split(cmd1[0], ' ');
	printf("split_arg[0] = %s\nsplit_srg[1] = %s\n", split_arg[0], split_arg[1]);
	path = make_path(split_arg[0], envp);
	split_arg[0] = ft_strdup(path);
	printf("split_arg[0] = %s\nsplit_srg[1] = %s\n", split_arg[0], split_arg[1]);
	execve(split_arg[0], split_arg, NULL);



	return (0);
}
