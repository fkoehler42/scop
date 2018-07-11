/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:38:57 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/28 19:55:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

unsigned int	ft_strtoui(char *str)
{
	int				i;
	unsigned long	val;

	i = 0;
	while (str[i] && (ft_isspace(str[i]) || str[i] == '-'))
		i++;
	val = strtoul(&(str[i]), NULL, 10);
	return ((unsigned int)val);
}

float			median_float(float min, float max)
{
	float tmp;

	if (min <= 0.0f && max <= 0.0f)
	{
		tmp = (min - max) / 2;
		return (max + tmp);
	}
	else
	{
		tmp = (max - min) / 2;
		return (min + tmp);
	}
	return (0.0f);
}

t_matrices		*get_matrices(void)
{
	t_env	*env;

	if (!(env = get_env_struct(NULL)))
		return (NULL);
	return (env->matrices);
}

t_env			*get_env_struct(t_env *env)
{
	static t_env	*save = NULL;

	if (env != NULL)
		save = env;
	return (save);
}
