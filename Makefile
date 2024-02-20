# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:03:46 by josfelip          #+#    #+#              #
#    Updated: 2024/02/20 17:29:35 by josfelip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DEBUG_NAME = push_swap_debug
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3

# Paths for libraries
LIB_PATH = ./lib
LIB_NAME = libft.a
# LIB_PRINTF_NAME = libftprintf.a
# LIB_PRINTF_PATH = ./lib/ft_printf

# Colors Definition 
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths definitions
HEADER_PATH = ./includes/
HEADER = $(HEADER_PATH)push_swap.h
OBJ_PATH = ./obj/
DEBUG_OBJ_PATH = ./obj_debug/
TESTS_PATH = ./tests/
SOURCES_PATH = ./sources/
SOURCES = $(shell find sources/ -name "*.c" | cut -d/ -f2)
MANDATORY_SOURCES = $(addprefix $(SOURCES_PATH), $(SOURCES))

ifdef WITH_DEBUG
  NAME = $(DEBUG_NAME)
  CFLAGS = $(DFLAGS)
  OBJ_PATH = ./obj_debug/
endif

ifdef DEBUG
	ifeq ($(DEBUG),1)
        CFLAGS += $(DFLAGS) -D DEBUG=1
	else ifeq ($(DEBUG),2)
        CFLAGS += $(DFLAGS) -D DEBUG=2
	else ifeq ($(DEBUG),3)
        CFLAGS += $(DFLAGS) -D DEBUG=3 
	else ifeq ($(DEBUG),4)
        CFLAGS += $(DFLAGS) -D DEBUG=4 
	else ifeq ($(DEBUG),5)
        CFLAGS += $(DFLAGS) -D DEBUG=5
	else ifeq ($(DEBUG),6)
        CFLAGS += $(DFLAGS) -D DEBUG=6
	else ifeq ($(DEBUG),7)
        CFLAGS += $(DFLAGS) -D DEBUG=7 
	else ifeq ($(DEBUG),8)
        CFLAGS += $(DFLAGS) -D DEBUG=8
	else ifeq ($(DEBUG),9)
        CFLAGS += $(DFLAGS) -D DEBUG=9
	else ifeq ($(DEBUG),10)
		CFLAGS += $(DFLAGS) -D DEBUG=10 
	endif
endif

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

all: libft $(OBJ_PATH) $(NAME)

libft:
	@make --directory=$(LIB_PATH) --no-print-directory
	
# libftprintf:
# 	@make --directory=$(LIB_PRINTF_PATH) --no-print-directory

debug:
	@make WITH_DEBUG=TRUE --no-print-directory

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIB_PATH) -lft
	@echo $(CYAN)" ----------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| PUSH_SWAP executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"----------------------------------------------"$(COLOR_LIMITER)
	@echo " "

$(OBJ_PATH)%.o: $(SOURCES_PATH)%.c $(HEADER)
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

valgrind: debug
	@echo $(GREEN)[Running memory checks]$(COLOR_LIMITER)
	@wget -nc https://raw.githubusercontent.com/jos-felipe/pipex/master/memory_checker.sh > /dev/null 2>&1
	@chmod +x memory_checker.sh
	@./memory_checker.sh

nor: 
	@echo $(GREEN)[Running Norminette]$(COLOR_LIMITER)
	@norminette -R CheckForbiddenSourceHeader $(SOURCES_PATH) $(HEADER_PATH)
	@echo $(GREEN)[Running Norminette on Libft]$(COLOR_LIMITER)
	@norminette -R CheckForbiddenSourceHeader $(LIB_PATH)
	@echo $(GREEN)[Running Norminette on Libftprintf]$(COLOR_LIMITER)
	@norminette -R CheckForbiddenSourceHeader $(LIB_PRINTF_PATH)

tester: all
	@echo $(GREEN)[Running tests]$(COLOR_LIMITER)
	@wget -nc https://raw.githubusercontent.com/jos-felipe/pipex/master/funcional_checker.sh > /dev/null 2>&1
	@chmod +x funcional_checker.sh
	@./funcional_checker.sh

qa: nor tester valgrind

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	-rm -rf $(OBJ_PATH)
	-rm -rf $(DEBUG_OBJ_PATH)
	@echo $(RED)[Removing test files]$(COLOR_LIMITER)
	-rm -rf $(TESTS_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(NAME)
	@rm -rf $(DEBUG_NAME)
	@make fclean -C $(LIB_PATH) --no-print-directory
# @make fclean -C $(LIB_PRINTF_PATH) --no-print-directory

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re libft libftprintf debug valgrind tester nor
