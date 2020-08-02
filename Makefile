NAME	=	cub3D

MLX		=	-lmlx -lm -framework OpenGL -framework AppKit

LIBFT	=	includes/libft

SRCS	=	sources/bitmap.c \
			sources/check_walls.c \
			sources/draw.c \
			sources/draw_forms.c \
			sources/errors_exits/code_error.c \
			sources/errors_exits/exit.c \
			sources/errors_exits/exit_two.c \
			sources/errors_exits/handle_error.c \
			sources/errors_exits/handle_error_two.c \
			sources/floor_cast.c \
			sources/initialisation.c \
			sources/initilialisation_two.c \
			sources/keys/handle_camera.c \
			sources/keys/handle_move.c \
			sources/keys/key_press.c \
			sources/keys/key_press_two.c \
			sources/main.c \
			sources/process.c \
			sources/raycastin_utils.c \
			sources/raycasting.c \
			sources/read_file.c \
			sources/read_file_struct.c \
			sources/read_map.c \
			sources/sprite.c \
			sources/sprite_list.c \
			sources/utils.c \
			sources/utils/assign_struct.c \
			sources/utils/partials.c \
			includes/get_next_line/get_next_line.c \
			includes/get_next_line/get_next_line_utils.c

SRCS_BONUS = bonus/bonus_init.c \
			bonus/bonus_utils.c \
			bonus/gun.c \
			bonus/minimap.c

OBJSRCS			=	$(SRCS:.c=.o)
OBJSRCSBONUS	=	$(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS) $(OBJSRCSBONUS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf Cub3D
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) -C $(LIBFT)
	@echo "\033[33m[Cub3D compilation...]"
	@gcc $(OBJSRCSBONUS) $(OBJSRCS) -I./sources/header.h -I./usr/include -Wall -Wextra -Werror $(MLX) $(LIBFT)/libft.a -o $(NAME)
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C $(LIBFT)

fclean : clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)