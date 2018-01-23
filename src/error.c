/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:33:45 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/26 21:50:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	empty_file(t_env **e)
{
	ft_printf("Error: Empty file\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	syntax_error(t_env **e)
{
	ft_printf("Error: Syntax incorrect\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	malloc_error(t_env **e)
{
	ft_printf("Error: Malloc failed\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	basic_error(char *argv, t_env **e)
{
	if (errno == EISDIR)
		ft_printf("Error: %s %s\n", argv, strerror(errno));
	else
		perror("Error");
	delete_env(e);
	exit(EXIT_SUCCESS);
}
