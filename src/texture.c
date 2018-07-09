/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:06:56 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/09 12:47:46 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_texture	*get_texture_src(t_texture **texture, const char *path)
{
	FILE				*fs;
	char				header[BMP_HEADER_SIZE];
	const char			*final_path;
	static const char	tex_dir[] = "../textures/";

	if (!(final_path = ft_strjoin(text_dir, path)))
		exit_error(ALLOC, NULL);
	if (!(fs = fopen(final_path, "r")))
		exit_error(OPEN, final_path);
	if (fread(header, 1, 54, fs) != 54 || header[0] != 'B' || header[1] != 'M')
		exit_error(TEXTURE_LOAD, "source is a not a well formatted .bmp file");
	
}

GLuint		load_texture(const char *path)
{
	t_texture	*texture;

	if (!(texture = (t_texture*)malloc(sizeof(*texture))))
		exit_error(ALLOC, NULL);
	get_texture_src(&texture, path);
}