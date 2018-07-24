/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:06:56 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/24 16:53:17 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		read_bmp_file_data(t_texture *texture, const char *file_path)
{
	FILE				*fs;
	char				header[BMP_HEADER_SIZE];

	if (!(fs = fopen(file_path, "r")))
		exit_error(OPEN, file_path);
	if (fread(header, 1, BMP_HEADER_SIZE, fs) != BMP_HEADER_SIZE
	|| header[0] != 'B' || header[1] != 'M')
		exit_error(TEXTURE_LOAD, NULL);
	if (!(texture->data_offset = *(unsigned int*)&(header[10])))
		texture->data_offset = BMP_HEADER_SIZE;
	if (!(texture->width = *(int*)&(header[18])) ||
	!(texture->height = *(int*)&(header[22])))
		exit_error(TEXTURE_LOAD, NULL);
	if (!(texture->bpp = *(unsigned short*)&(header[28])))
		exit_error(TEXTURE_LOAD, NULL);
	texture->width < 0 ? texture->width = -texture->width : 0;
	texture->height < 0 ? texture->height = -texture->height : 0;
	texture->img_size = texture->width * texture->height * (texture->bpp / 8);	
	if (!(texture->buff_data = (unsigned char*)malloc(sizeof(unsigned char) *
	texture->img_size)))
		exit_error(ALLOC, NULL);
	if ((fread(texture->buff_data, 1, texture->img_size, fs)) != texture->img_size)
		exit_error(TEXTURE_LOAD, NULL);
	// printf("\noffset : %u\nwidth : %u\nheight : %u\nbits per pixel : %hu\nimg size : %u\n", texture->data_offset, texture->width, texture->height, texture->bpp, texture->img_size);
	fclose(fs);
}

static unsigned char	*reverse_img_data(unsigned char *buff, unsigned int img_size,
unsigned int line_size)
{
	unsigned int	h;
	unsigned int	j;
	unsigned char	*img_data;

	h = 0;
	if (!(img_data = (unsigned char*)malloc(sizeof(unsigned char) * img_size)))
		exit_error(ALLOC, NULL);
	while (img_size > 0)
	{
		img_size -= line_size;
		j = 0;
		while (j < line_size)
		{
			img_data[h + j] = buff[img_size + j + 2];
			img_data[h + j + 1] = buff[img_size + j + 1];
			img_data[h + j + 2] = buff[img_size + j];
			j += 3;
		}
		h += line_size;
	}
	return (img_data);
}

static void				get_texture_data(t_texture *texture, const char *filename)
{
	char				*full_path;

	if (!(full_path = ft_strjoin("../textures/", filename)))
		exit_error(ALLOC, NULL);
	read_bmp_file_data(texture, full_path);
	ft_strdel(&full_path);
	texture->img_data = reverse_img_data(texture->buff_data, texture->img_size,
	texture->width * (texture->bpp / 8));
	ft_strdel((char**)&texture->buff_data);
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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0,
	GL_RGB, GL_UNSIGNED_BYTE, texture->img_data);
	glBindTexture(GL_TEXTURE_2D, 0);
	ft_strdel((char **)&texture->img_data);
	free(texture);
	return (texture_id);
}