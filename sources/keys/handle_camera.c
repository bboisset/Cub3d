
#include "../header.h"

void handle_cam_right(t_display_config *display_config)
{
	double old_dir_x;
	double old_fov_x;
	
	check_active_key(display_config);
	old_dir_x = D_CONFIG->init_dir.x;
	old_fov_x = D_CAM->fov.x;
	D_CONFIG->init_dir.x = D_CONFIG->init_dir.x * cos(-rotSpeed) -
	D_CONFIG->init_dir.y * sin(-rotSpeed);
	D_CONFIG->init_dir.y = old_dir_x * sin(-rotSpeed) + D_CONFIG->init_dir.y *
	cos(-rotSpeed);
	D_CAM->fov.x = D_CAM->fov.x * cos(-rotSpeed) - D_CAM->fov.y *
	sin(-rotSpeed);
	D_CAM->fov.y = old_fov_x * sin(-rotSpeed) + D_CAM->fov.y * cos(-rotSpeed);
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);//clean image instead
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
									D_CONFIG->resolution.y);
	reload_scene(display_config, 0);
}

void handle_cam_left(t_display_config *display_config)
{
	double old_dir_x;
	double old_fov_x;
	
	check_active_key(display_config);
	old_dir_x = D_CONFIG->init_dir.x;
	old_fov_x = D_CAM->fov.x;
	D_CONFIG->init_dir.x = D_CONFIG->init_dir.x * cos(rotSpeed) -
	D_CONFIG->init_dir.y * sin(rotSpeed);
	D_CONFIG->init_dir.y = old_dir_x * sin(rotSpeed) + D_CONFIG->init_dir.y *
	cos(rotSpeed);
	D_CAM->fov.x = D_CAM->fov.x * cos(rotSpeed) - D_CAM->fov.y *
	sin(rotSpeed);
	D_CAM->fov.y = old_fov_x * sin(rotSpeed) + D_CAM->fov.y * cos(rotSpeed);
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);//clean image instead
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
									D_CONFIG->resolution.y);
	reload_scene(display_config, 0);
}
