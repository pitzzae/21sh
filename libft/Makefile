#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:18:23 by gtorresa          #+#    #+#              #
#*   Updated: 2016/06/06 04:26:30 by gtorresa         ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c\
	ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c\
	ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c\
	ft_tolower.c ft_toupper.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	ft_lstdel.c ft_lstadd.c ft_lstaddend.c ft_lstiter.c ft_lstmap.c\
	ft_lstsplit.c ft_lstprintstr.c ft_lstprintnbr.c ft_str_replace_chr.c\
	ft_lstlen.c ft_lstring.c ft_lstdup.c ft_strfocur.c get_next_line.c\
	ft_strjoin_free.c ft_realloc.c ft_tab_realloc.c ft_strocur.c ft_strlocur.c\
	ft_strcat_l.c ft_bufcpy.c ft_strisprint.c ft_strswap.c ft_date_time.c \
	ft_lst_env_new.c ft_lst_to_env.c ft_lst_get_env.c ft_lst_edit_env.c \
	ft_lst_add_env.c ft_lst_rm_env.c ft_strsplit_len.c ft_str_replace_str.c \
	ft_strsub_free.c ft_myputchar.c ft_lstaddend_free.c ft_udel.c \
	ft_strocur_slash.c ft_stradd_slash.c ft_tabdup.c

CFLAGS = -Wall -Wextra -Werror

O_DIR = ./obj

OBJS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "\nCreating archive library."
	@ranlib $@
	@echo "Indexing archive library."

$(O_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(O_DIR)
	@printf "."
	@gcc $(CFLAGS) -c $< -I./includes -o $@

clean:
	@rm -rf $(O_DIR)
	@echo "Delete obj."

fclean: clean
	@rm -rf $(NAME)
	@echo "Delete $(NAME)."

re: fclean
	@make all
	@echo "Make library."

.PHONY: all clean fclean re
