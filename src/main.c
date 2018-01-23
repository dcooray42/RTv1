/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:33:07 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:51:36 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int argc, char **argv)
{
	t_env	*e;

	e = NULL;
	if (argc == 2)
	{
		read_file(argv[1], &e);
		num_obj_light(e);
		rt(e);
	}
	else
		ft_printf("Usage: %s <filename>\n", argv[0]);
	return (0);
}
