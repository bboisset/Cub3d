# include "../header.h"

t_map_config	*create_config()
{
	t_map_config	*config;

	config = init_config();
	if (config == NULL)
		return (NULL);
}