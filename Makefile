NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c\
      ft_handle_hex.c\
      puthex.c

OBJS = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all
