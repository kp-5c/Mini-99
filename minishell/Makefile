# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:35:48 by dbhujoo           #+#    #+#              #
#    Updated: 2025/08/13 08:52:41 by dbhujoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
BONUS_NAME	= pipex_bonus
CC		= cc
CFLAGS		= -Wall -Werror -Wextra -g -Iincludes -lreadline
AR		= ar
ARFLAGS		= rcs
OBJ_DIR		= obj
SRCS_SRC	= srcs/pipex.c \
		  srcs/pipex_open.c \
		  srcs/pipex_check_arg.c \
		  srcs/pipex_get_env.c \
		  srcs/pipex_get_path.c \
		  srcs/pipex_exec.c \
		  srcs/pipex_pipe.c

BONUS_SRC	= 

SRC		= $(SRCS_SRC)

OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	= $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

RESET 		= \033[0m
GREEN 		= \033[0;32m
BLUE   		= \033[0;34m
YELLOW		= \033[1;33m

all: message $(NAME)

bonus : $(BONUS_NAME)
	
message:
	@printf "$(GREEN)compilation Minishell...$(NC)\n"

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)Minishell complete$(NC)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@printf "$(GREEN)Minishell_bonus complete$(NC)\n"
	
$(OBJ_DIR)/%.o: %.c
	@printf "Compilation $<\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Cleaning objects\n"
	@rm -f $(OBJ) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@printf "Cleaning all\n"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
	@printf "$(GREEN)Recompil de Minishell...$(NC)\n"

.PHONY: all clean fclean re
