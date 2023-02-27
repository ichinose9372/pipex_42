/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:58:43 by yichinos          #+#    #+#             */
/*   Updated: 2023/02/27 15:01:55 by ichinoseyuu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
