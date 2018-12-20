# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 12:27:37 by gguarnay          #+#    #+#              #
#    Updated: 2018/12/15 21:55:40 by gguarnay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
INCLUDES=-I includes/
LAGS=-Wall -Werror -Wextra
FLAGS_D=-Wall -Werror -Wextra -fsanitize=address
DFLAG=-g -L. -lft

NUM=ft_atoi.c ft_itoa.c 
MEM=ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memdel.c ft_memmove.c ft_memset.c 
IS=ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
LST=ft_lstadd.c ft_lstat.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
   	ft_lstmap.c ft_lstnew.c ft_lstpushback.c ft_lstsize.c ft_lstsplit.c
PUT=ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
   	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
STR=ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
   	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
   	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
   	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
   	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c
CHAR=ft_tolower.c ft_toupper.c
BONUS=ft_printbits.c
SOURCE=$(NUM) $(MEM) $(IS) $(LST) $(PUT) $(STR) $(CHAR) $(BONUS) 

FILES=$(SOURCE)
BINARY=$(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(FILES) $(FLAGS)
	ar rc $(NAME) $(BINARY)
	ranlib $(NAME)

debug: re
	gcc $(FLAGS_D) $(DFLAG) -o debug.out $(D); ./debug.out

ldebug: re
	gcc $(FLAGS_D) $(DFLAG) -o debug.out $(D); lldb ./debug.out

dclean:
	/bin/rm -f debug.out

clean:
	/bin/rm -f $(BINARY)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
