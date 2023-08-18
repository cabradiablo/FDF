NAME_L = fdf.linux
NAME_M = fdf.mac

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3 -g3 -fsanitize=address
#MAC
LIBRARIES_M = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_M_DIRECTORY)
INCLUDES_M = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_M_HEADERS)
#LINUX
LIBRARIES_L = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_L_DIRECTORY)
INCLUDES_L = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_L_HEADERS)

#LIBFT
LIBFT_DIRECTORY = ./Libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

#MINILIBX
MINILIBX_L_DIRECTORY = minilibx_linux/
MINILIBX_L = $(MINILIBX_L_DIRECTORY)libmlx.a
MINILIBX_L_HEADERS = $(MINILIBX_L_DIRECTORY)

MINILIBX_M_DIRECTORY = minilibx_macos/
MINILIBX_M = $(MINILIBX_M_DIRECTORY)libmlx.a
MINILIBX_M_HEADERS = $(MINILIBX_M_DIRECTORY)


#HEADERS
HEADERS_LIST = fdf.h			\
				error.h			\


HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#SOURCES
SOURCES_DIRECTORY = ./sources/

SOURCES_LIST = main.c			\
	       		map.c			\
				error.c			\
				free.c			\
				utils.c			\

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#OBJECTS
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all linux clean fclean re

#NORMS
all: $(NAME_M)

$(NAME_M): $(LIBFT) $(MINILIBX_M) $(OBJECTS_DIRECTORY_M) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES_M) $(OBJECTS) $(LIBRARIES_M)  -o $(NAME)
	@echo "\n$(NAME_M): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_M): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY_M):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_M): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY_M)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES_M) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME_M): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX_M):
	@echo "$(NAME_M): $(GREEN)Creating $(MINILIBX_M)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_M_DIRECTORY)

linux: $(NAME_L)

$(NAME_L): $(LIBFT) $(MINILIBX_L) $(OBJECTS_DIRECTORY_L) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES_L) $(OBJECTS) $(LIBRARIES_L)  -o $(NAME)
	@echo "\n$(NAME_L): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_L): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY_L)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_L): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"
	@$(CC) $(FLAGS) -c $(INCLUDES_L) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX_L):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX_L)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_L_DIRECTORY)


mclean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_M_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_M): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME_M): $(RED)object files were deleted$(RESET)"

lclean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_L_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_L): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME_L): $(RED)object files were deleted$(RESET)"


fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all