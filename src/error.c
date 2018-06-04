/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:54:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/04 14:47:56 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	put_error(t_errnum err, char *str) {
	ft_putstr_fd("scop: ", 2);
	if (err == NB_ARG)
		ft_putendl_fd("One (and only one) argument is expected", 2);
	else if (err == OPEN || err == ALLOC)
		perror(str);
	else if (err == MODEL_DATA)
		ft_putendl_fd("Not enough data to build a model", 2);
}