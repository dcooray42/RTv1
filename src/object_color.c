/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:31:47 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:25:53 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	object_color(char *line, int i, t_env **e)
{
	char	*str;
	int		j;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else if (i == 1)
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	str = line;
	j = 0;
	while (!ft_isspace(*str) && *str != '}' && *str != '\0')
	{
		j++;
		str++;
	}
	object_color_bis(line, i, j, e);
}

void	object_color_bis(char *line, int i, int j, t_env **e)
{
	t_obj	*obj;

	obj = (t_obj *)(*e)->list->content;
	if (i == 1)
	{
		obj->clr->r = (double)get_color(line, e);
		line += j;
		object_color(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		obj->clr->g = (double)get_color(line, e);
		line += j;
		object_color(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		obj->clr->b = (double)get_color(line, e);
		line += j;
	}
	object_ori_rot_final(line, e);
}

int		get_color(char *line, t_env **e)
{
	int		i;
	char	*str;
	int		clr;

	i = 0;
	clr = 0;
	if (*line != '\0' && *(line + 1) != '\0' && *line == '0' &&
			ft_toupper(*(line + 1)) == 'X')
	{
		line += 2;
		str = line;
		while (*str != '\0' && ft_isxdigit(*str))
		{
			str++;
			i++;
		}
		if ((ft_isspace(*str) || *str == '}') && *str != '\0' && i == 2)
			clr = hex_to_int(line, i);
		else
			syntax_error(e);
	}
	else
		syntax_error(e);
	return (clr);
}

int		ret_power(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	return (ret_power(nbr, power - 1) * nbr);
}

int		hex_to_int(char *str, int power)
{
	int	i;
	int	pwr;
	int	tmp;
	int	clr;

	i = 1;
	clr = 0;
	while (ft_isxdigit(*str) && *str != '\0')
	{
		pwr = ret_power(16, power - i);
		if (ft_isalpha(*str))
			tmp = (ft_toupper(*str) - 'A' + 10) * pwr;
		else
			tmp = (*str - '0') * pwr;
		clr += tmp;
		str++;
		i++;
	}
	return (clr);
}
