/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:38:57 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/15 19:49:13 by fkoehler         ###   ########.fr       */
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