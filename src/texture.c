/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:06:56 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/10 11:14:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		read_bmp_file_header(t_texture *texture, const char *filepath)
{
	FILE				*fs;
	char				header[BMP_HEADER_SIZE];

	if (!(fs = fopen(file_path, "r")))
		exit_error(OPEN, final_path);
	if (fread(header, 1, BMP_HEADER_SIZE, fs) != BMP_HEADER_SIZE
	|| header[0] != 'B' || header[1] != 'M')
		exit_error(TEXTURE_LOAD, NULL);
	if (!(texture->data_offset = *(int*)&(header[0x0A])))
		texture->data_offset = BMP_HEADER_SIZE;
	if (((texture->width = *(int*)&(header[0x12])) <= 0) ||
	((texture->height = *(int*)&(header[0x16])) <= 0))
		exit_error(TEXTURE_LOAD, NULL);
	if (!(texture->img_size = *(int*)&(header[0x22])))
		texture->img_size = texture->width * texture->height * 3;
	
	if (!(texture->buff_data = (unsigned char*)malloc(sizeof(unsigned char) *
	texture->img_size * 3)))
		exit_error(ALLOC, NULL);
	if (!(fread(texture->buff_data, 1, texture->img_size * 3, fs)))
		exit_error(TEXTURE_LOAD, NULL);
	fclose(fs);
}

static void		get_texture_data(t_texture *texture, const char *filename)
{
	char				*full_path;

	if (!(full_path = ft_strjoin("../textures/", filename)))
		exit_error(ALLOC, NULL);
	read_bmp_file_header(texture, full_path);
}

GLuint			load_texture(const char *filename)
{
	t_texture	*texture;
	GLuint		texture_id;

	if (!(texture = (t_texture*)malloc(sizeof(*texture))))
		exit_error(ALLOC, NULL);
	get_texture_data(texture, filename);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glActiveTexture(GL_TEXTURE0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0,
	GL_RGB, GL_UNSIGNED_BYTE, texture->data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	ft_strdel((char **)&texture->data);
	free(texture);
	return (texture_id);
}