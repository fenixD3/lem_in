
NAME_FILE = lem-in
LIB_NAME = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

#SRC_GEN = ./stack/
#SRC_CHECKER = ./checker_dir/
SRC_READING = ./reading/
HEAD_PATH = ./includes/
LIB_PATH = ./libft/

#SRC_FILES_GEN =
#SRC_FILES_CHECKER =
SRC_FILES_READING = readfile.c making_lists.c

#SRCS_GEN = $(addprefix $(SRC_GEN),$(SRC_FILES_GEN))
#SRCS_CHECKER = $(addprefix $(SRC_CHECKER),$(SRC_FILES_CHECKER))
SRCS_READING = $(addprefix $(SRC_READING),$(SRC_FILES_READING))

#OBJS_GEN = $(SRC_FILES_GEN:.c=.o)
#OBJS_CHECKER = $(SRC_FILES_CHECKER:.c=.o)
OBJS_READING = $(SRC_FILES_READING:.c=.o)


all: $(NAME_FILE)

$(NAME_FILE): $(LIB_NAME) $(OBJS_READING)
	@gcc -o $(NAME_FILE) $(OBJS_READING) -L$(LIB_PATH) -lft

$(OBJS_READING):
	@gcc -c $(SRCS_READING) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS_READING)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME_FILE)
	@make -C $(LIB_PATH) fclean

re: fclean all