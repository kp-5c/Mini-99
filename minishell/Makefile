# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:35:48 by dbhujoo           #+#    #+#              #
#    Updated: 2025/08/18 16:30:17 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
BONUS_NAME	= minishell_bonus
CC		= cc
CFLAGS		= -Wall -Werror -Wextra -g -Iincludes
AR		= ar
ARFLAGS		= rcs
OBJ_DIR		= obj
FILES	= utils/singleton.c \
				utils/free.c \
				main/main.c \
				parsing_tokenisation/parsing.c\
				parsing_tokenisation/token.c
				
HEADER		= includes/minishell.h

BONUS_SRC	= 

SRC_DIR		= srcs
SRCS		= $(addprefix $(SRC_DIR)/, $(FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

RESET 		= \033[0m
GREEN 		= \033[0;32m
BLUE   		= \033[0;34m
YELLOW		= \033[1;33m

all: message $(NAME)

bonus : $(BONUS_NAME)
	
message:
	@printf "$(GREEN)compilation Minishell...$(RESET)\n"

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline
	@printf "$(GREEN)Minishell complete$(RESET)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@printf "$(GREEN)Minishell_bonus complete$(RESET)\n"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $(notdir $<)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)Cleaning objects$(RESET)\n"
	@rm -f $(OBJ) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@printf "$(BLUE)Cleaning all$(RESET)\n"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
	@printf "$(GREEN)Recompil de Minishell...$(RESET)\n"

.PHONY: all clean fclean re
