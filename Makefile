#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 16:40:23 by gtorresa          #+#    #+#              #
#*   Updated: 2016/06/11 19:27:01 by gtorresa         ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME = 21sh

LIB_DIR = ./libft

LIB_NAME = $(LIB_DIR)/libft.a

CFLAGS=-Wall -Wextra -Werror

SRCS_DIR = ./srcs/

SRCS = $(SRCS_DIR)main.c
SRCS += $(SRCS_DIR)ft_init_env.c
SRCS += $(SRCS_DIR)ft_history.c
SRCS += $(SRCS_DIR)ft_exec_cmd.c
SRCS += $(SRCS_DIR)ft_get_list_cmd.c
SRCS += $(SRCS_DIR)ft_builtins_env.c
SRCS += $(SRCS_DIR)ft_builtins_cd.c
SRCS += $(SRCS_DIR)ft_builtins_history.c
SRCS += $(SRCS_DIR)ft_check_env.c
SRCS += $(SRCS_DIR)ft_puterror.c
SRCS += $(SRCS_DIR)ft_get_cmd_argv.c
SRCS += $(SRCS_DIR)ft_add_space.c
SRCS += $(SRCS_DIR)ft_redirect_cmd.c
SRCS += $(SRCS_DIR)ft_terminos.c
SRCS += $(SRCS_DIR)ft_action_key.c
SRCS += $(SRCS_DIR)ft_action_key_tool.c
SRCS += $(SRCS_DIR)ft_action_key_fn1.c
SRCS += $(SRCS_DIR)ft_action_key_fn2.c
SRCS += $(SRCS_DIR)ft_action_key_fn3.c
SRCS += $(SRCS_DIR)ft_close_cmd.c
SRCS += $(SRCS_DIR)ft_close_read_input.c
SRCS += $(SRCS_DIR)ft_close_all_quote.c
SRCS += $(SRCS_DIR)ft_close_cmd_fn1.c
SRCS += $(SRCS_DIR)ft_read_redirect_cmd.c
SRCS += $(SRCS_DIR)ft_isfd_redirect.c
SRCS += $(SRCS_DIR)ft_add_argv_cmd.c
SRCS += $(SRCS_DIR)ft_redirect_tool.c
SRCS += $(SRCS_DIR)ft_redirect_pipe.c
SRCS += $(SRCS_DIR)ft_getfd_in.c
SRCS += $(SRCS_DIR)ft_getfd_out.c
SRCS += $(SRCS_DIR)ft_apply_fd_redirect.c

all: ${NAME}

$(NAME):
	@make -C $(LIB_DIR)
	@echo "Make $(NAME)"
	@gcc -o $(NAME) $(SRCS) -lncurses -I./includes -L$(LIB_DIR) -lft

fclean: clean
	@rm -f $(NAME)
	@echo "Delete $(NAME)"

clean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(LIB_NAME)
	@echo "Delete $(LIB_NAME)"

re: fclean all
