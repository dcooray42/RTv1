/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 08:37:20 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:23:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cone(char *line, t_obj *obj, t_env **e)
{
	int	i;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	i = 0;
	while (!ft_isspace(*line) && *line != '}' && *line != '\0')
	{
		i++;
		line++;
	}
	line -= i;
	obj->k = tan(((ft_atoif(line) * M_PI) / 180) / 2);
	obj->o_axis = create_vect(*e);
	line += i;
	object_ori_rot_final(line, e);
}
