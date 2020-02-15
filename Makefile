NAME_FILE = lem-in

FLAGS = -Wall -Wextra -Werror

LIB_PRINTF = ./ft_printf/libftprintf.a
LIB_PRINTF_NAME = -lftprintf
LIB_PRINTF_PATH = ./ft_printf/
LIB_PRINTF_INCL = ./ft_printf/includes/

LIBFT_NAME = -lft
LIB_PATH = ./libft/

LIB_SDL_NAME = -F ./ -framework SDL2
LIB_SDL_PATH = ./SDL2.framework/
LIB_SDL_INCL = ./SDL2.framework/Headers/

SRCS = ants.c count_ant_for_ways.c finding.c mark_way.c waylist.c count_room_param.c \
	draw_ant_helper.c viz_ant.c vizual_creator.c vizual_helper.c check.c create_rooms_links.c \
	making_lists.c making_rooms.c readfile.c SDL2_framerate.c SDL2_gfxPrimitives.c \
	SDL2_rotozoom.c go_exit.c main.c check_duplicates.c

OBJS = $(SRCS:.c=.o)

HEADER_PATH = ./includes/
HEADER_FILES = lem_in.h readfile.h vizual.h ways_and_ants.h
HEADERS = $(addprefix $(HEADER_PATH),$(HEADER_FILES))

HEADER_SDL2_GFX_PATH = ./SDL2_gfx/

vpath %.c ./read_and_check ./SDL2_gfx ./vizual ./ways_and_ants

all: $(NAME_FILE)

$(NAME_FILE): $(LIB_PRINTF) $(OBJS)
	@gcc -o $(NAME_FILE) $(OBJS) -L$(LIB_PATH) $(LIBFT_NAME) -L$(LIB_PRINTF_PATH) $(LIB_PRINTF_NAME) \
	-L$(LIB_SDL_PATH) $(LIB_SDL_NAME)

$(LIB_PRINTF):
	@make -C $(LIB_PRINTF_PATH)

$(OBJS): %.o: %.c $(HEADERS)
	@gcc -c $< -I$(HEADER_PATH) -I$(LIB_PATH) -I$(LIB_PRINTF_INCL) -I$(LIB_SDL_INCL) \
	-I$(HEADER_SDL2_GFX_PATH) $(FLAGS) -O3 -o $@

.PHONY: clean fclean re
clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PRINTF_PATH) clean

fclean: clean
	@rm -f $(NAME_FILE)
	@make -C $(LIB_PRINTF_PATH) fclean

re: fclean all
