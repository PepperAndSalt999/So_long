CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./static/includes/so_long.h

HEADER += mlx/

NAME = so_long

OBJECTS =	./main.o \
			./init/init_mlx.o \
			./init/init_img.o \
			./init/init_lookup.o \
			./error_handling/ft_itoa.o \
			./error_handling/ft_putstr.o \
			./error_handling/free_struct.o \
			./error_handling/error_display.o \
			./parse_and_check_map/other_utils/others.o \
			./parse_and_check_map/other_utils/moving.o \
			./parse_and_check_map/parse_and_check_map.o \
			./parse_and_check_map/check/check_characters.o \
			./parse_and_check_map/parse/get_next_line.o \
			./parse_and_check_map/parse/get_next_line_utils.o \
			./interpreter/render.o \
			./interpreter/interpreter.o \
			./interpreter/hooks/key_hooks.o \
			./interpreter/hooks/hooks_utils.o

$(OBJECTS): CFLAGS += -Imlx

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(OBJECTS): $(HEADER)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all