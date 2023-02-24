/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:02:14 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/24 15:13:13 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*create_path(**env)
{
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