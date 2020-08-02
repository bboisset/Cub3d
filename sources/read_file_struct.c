#include "header.h"

t_img_data	*load_textures_struct(void *img_ptr, t_map_config *config)
{
	t_img_data *img_data;
	
	if (!(img_data = (t_img_data*)malloc(sizeof(t_img_data))) || !img_ptr)
		return (NULL);
	img_data->data_img = mlx_get_data_addr(img_ptr, &img_data->bpp, &img_data->sizeline, &img_data->endian);
	img_data->temp = img_ptr;
	if (config)
		TEXTURE->loadedTexture += 1;
	return (img_data);
}

int	load_textures(t_map_config *config, t_data *data)
{
	int		w;
	void	*img_ptr;
	
	w = 256;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, TEXTURE->north_texture_path, &w, &w);
	TEXTURE->north_texture = load_textures_struct(img_ptr, config);
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, TEXTURE->south_texture_path, &w, &w);
	TEXTURE->south_texture = load_textures_struct(img_ptr, config);
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, TEXTURE->east_texture_path, &w, &w);
	TEXTURE->east_texture = load_textures_struct(img_ptr, config);
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, TEXTURE->west_texture_path, &w, &w);
	TEXTURE->west_texture = load_textures_struct(img_ptr, config);
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, TEXTURE->sprite_texture_path, &w, &w);
	TEXTURE->sprite_texture = load_textures_struct(img_ptr, config);
	if (!TEXTURE->north_texture || !TEXTURE->south_texture || !TEXTURE->east_texture || !TEXTURE->west_texture || !TEXTURE->sprite_texture)
		return (texture_error(config));
	return (0);
}
