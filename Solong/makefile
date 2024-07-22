NAME 			= so_long

CC 				= gcc
FLAGS 			= -Wall -Wextra -Werror

SRC 			= ./src/game_cor/main.c \
					./src/game_cor/so_long.c \
					./src/game_cor/set_sprites.c \
					./src/game_cor/set_player.c \
					./src/game_cor/put_image.c \
					./src/game_cor/mov.c \
					./src/game_cor/end_game.c \
					./src/game_cor/count_coins.c \
					./src/ft_err.c \
					./src/get_map/is_ber.c \
					./src/get_map/map_init.c \
					./src/get_map/is_rec.c \
					./src/get_map/is_logic.c \
					./src/free_map.c \

OBJ				= main.o \
					so_long.o \
					set_sprites.o \
					set_player.o \
					put_image.o \
					mov.o \
					end_game.o \
					count_coins.o \
					ft_err.o \
					is_ber.o \
					map_init.o \
					is_rec.o \
					is_logic.o \
					free_map.o

MINILIBX_PATH	= ./src/minilibx

LIBFT_PATH = ./src/libft
LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME):	$(LIBFT) mlx
			@$(CC) $(FLAGS) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

mlx:
	@make -C $(MINILIBX_PATH) all

clean:
	@rm -f $(OBJ)
	@make -C $(MINILIBX_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean:
	@rm -f $(OBJ)
	@make -C $(MINILIBX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re