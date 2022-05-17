NAME = cub3D_bonus

LIBINC = -L minilibx-linux -lmlx -lX11 -lXext -lm

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

CC = clang
CFLAGS = -Wall -Wextra -Werror #-g
MEM =  #-fsanitize=thread

ifeq ($(TMEM),0)
MEM =
endif

INC = 	function.h \
		get_next_line.h

SRC = main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			keys/ft_key.c \
			keys/ft_key_2.c \
			utils/draw.c \
			utils/colors.c \
			utils/ft_calloc.c \
			utils/ft_split.c \
			utils/utils.c \
			utils/utils_2.c \
			utils/utils_3.c \
			utils/utils_4.c \
			utils/utils_5.c \
			utils/mlx.c \
			parsing/parsing.c \
			parsing/convert_param.c \
			parsing/convert_param_2.c \
			parsing/adjust_map.c \
			parsing/launch_game.c \
			parsing/launch_game_2.c \
			parsing/put_texture.c \
			parsing/paint_world.c \
			init/init.c \
			error/error.c \
			check/check.c \
			check/check_color.c \
			check/check_map_1.c \
			check/check_map_2.c \
			check/check_map_3.c \
			parsing/secure_map.c

OBJS = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

all: ${NAME}

bonus: ${NAME}

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
GREY="\033[0;37m"
RESET="\033[m"

$(NAME): ${OBJS}
	make -C minilibx-linux
	${CC} ${CFLAGS} ${MEM} ${OBJS} -I./${INCDIR} -o $@ ${LIBINC}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${MEM} -I./${INCDIR} -c $< -o $@

re: fclean all

clean:
	@echo  "Cleaning objects\c"
	@rm -rf ${OBJDIR}
	make -C minilibx-linux clean
	@echo "\033[32m\t[OK]\033[0m"

fclean: clean
	@echo  "Removing minishell\c"
	make -C minilibx-linux clean
	@rm -rf ${NAME}
	@echo "\033[32m\t[OK]\033[0m"

.PHONY : all clean re fclean 