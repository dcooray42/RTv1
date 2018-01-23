# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcooray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 09:28:36 by dcooray           #+#    #+#              #
#    Updated: 2017/07/10 16:49:26 by dcooray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = $(addprefix ./src/, main.c\
				read.c\
				read_bis.c\
				error.c\
				delete.c\
				delete_bis.c\
				event.c\
				param_scene.c\
				camera.c\
				camera_bis.c\
				valid_file.c\
				object.c\
				object_bis.c\
				object_ter.c\
				object_type.c\
				object_type_bis.c\
				object_color.c\
				light.c\
				light_bis.c\
				mlx_function.c\
				rt.c\
				rt_bis.c\
				event_setup.c\
				event_setup_bis.c\
				event_camera.c\
				event_object.c\
				event_light.c\
				calculus.c\
				calculus_bis.c\
				calculus_ter.c\
				color.c\
				color_bis.c\
				render.c\
				intersection.c\
				rotation.c\
				shade.c\
				sphere.c\
				plane.c\
				cylinder.c\
				cone.c\
				inter_cc.c)

OBJ = $(addprefix ./obj/, $(notdir $(SRC:.c=.o)))

PATHFT = ./libft

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I ./include

MACOSVERS := $(shell (sw_vers -productVersion | cut -b 1-5))

SIERRA = ./mlx/sierra

ELCAPITAN = ./mlx/el_capitan

LIBFT = -L$(PATHFT) -lft

OPENCL = -framework OpenCL

ifeq ($(MACOSVERS),10.11)
	MLXPATH = -L$(ELCAPITAN)
else ifeq ($(MACOSVERS),10.12)
	MLXPATH = -L$(SIERRA)
endif

MLX = $(MLXPATH) -lmlx -framework OpenGL -framework Appkit

all: libft.a mlx.a $(NAME)

libft.a:
	make -C $(PATHFT)

mlx.a:
ifeq ($(MACOSVERS),10.11)
	make -C $(ELCAPITAN)
else ifeq ($(MACOSVERS),10.12)
	make -C $(SIERRA)
endif

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(INCLUDE) $(LIBFT) $(MLX) $(OPENCL) $(OBJ)

./obj/%.o: ./src/%.c
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $^

clean:
	make -C $(ELCAPITAN) clean
	make -C $(SIERRA) clean
	make -C $(PATHFT) clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C $(PATHFT) fclean
	/bin/rm -f $(NAME)

re: fclean all
