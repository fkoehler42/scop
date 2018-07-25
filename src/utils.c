/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:38:57 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 11:40:04 by fkoehler         ###   ########.fr       */
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
