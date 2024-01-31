LIB = ar rcs #no se que hace esto

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a #no se que es una biblioteca estatica
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c/
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c/
ft_toupper.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

#no entiendo esto
all: $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<