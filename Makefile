# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 11:22:45 by hshi-yun          #+#    #+#              #
#    Updated: 2025/03/08 19:19:04 by hshi-yun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE
NAME = so_long

# COMPILER
CC = cc
CFLAGS = -Wall -Wextra -Werror

# DETECT OS
UNAME_S := ${shell uname -s}

# MINILIBX PATH
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

ifeq (${UNAME_S}, Linux)
	MLXFLAGS = -L${MLX_DIR} -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz
	INCLUDES = -I/usr/include -I${MLX_DIR}
else
	MLXFLAGS = -L${MLX_DIR} -lmlx_Darwin -L/opt/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	INCLUDES = -I/opt/X11/include -I${MLX_DIR}
endif

SRC = so_long.c utils/error_utils.c validation/input_file_validation.c
OBJ = ${SRC:.c=.o}

LIBFT = ./libft

all: ${NAME}

# Clone and configure MiniLibX if not already present
${MLX_DIR}:
	@if [ ! -d "${MLX_DIR}" ]; then \
		echo "MLX library not found, cloning from Github..."; \
		git clone ${MLX_REPO} ${MLX_DIR} || { echo "Error: Failed to clone MLX repository."; exit 1; }; \
		cd ${MLX_DIR} && { \
			if [ -f "configure" ]; then \
				./configure || { echo "Error: Failed to configure MLX."; exit 1; }; \
			fi; \
			make || { echo "Error: Failed to build MLX."; exit 1; }; \
		}; \
		echo "MLX library cloned and configured successfully."; \
	fi

%.o: %.c
		@echo "Coverting .c files to .o files"
		@${CC} ${CFLAGS} ${INCLUDES} -I${LIBFT} -c $< -o $@

${NAME}: ${MLX_DIR} ${OBJ}
			@echo "Building..."
			@make -C ${LIBFT} > /dev/null 
			cp ${LIBFT}/libft.a . 
			${CC} ${CFLAGS} ${OBJ} ${MLXFLAGS} -Llibft -lft -o ${NAME} 
			@echo "Built successfully"

libft:
		make -C ${LIBFT} > /dev/null

clean:
		@echo "Cleaning..."
		@make clean -C ${LIBFT} > /dev/null
		@rm -f ${OBJ}
		@echo "Clean up successfully!"

fclean: clean
		@echo "Full cleaning..."
		@rm -f ${NAME}
		@rm -rf ${MLX_DIR}
		@make fclean -C ${LIBFT} > /dev/null
		@echo "Full clean up successfully!"

re:		fclean all

.PHONY: all clean fclean re check_tgz