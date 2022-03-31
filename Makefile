NAME  = libftprintf.a

FT_PRINTF = ./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c ./libft/ft_isprint.c \
./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c \
./libft/ft_strlcat.c ./libft/ft_toupper.c ./libft/ft_tolower.c ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c \
./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c \
./libft/ft_lstnew_bonus.c ./libft/ft_lstadd_front_bonus.c ./libft/ft_lstsize_bonus.c ./libft/ft_lstlast_bonus.c \
./libft/ft_lstadd_back_bonus.c ./libft/ft_lstdelone_bonus.c ./libft/ft_lstclear_bonus.c ./libft/ft_lstiter_bonus.c \
ft_printf.c ./libft/ft_int_to_hex.c ./libft/ft_make_big.c ./libft/ft_uitoa.c ft_printf_additional_funcs.c ft_output_for_flags.c\
./libft/ft_lstnew_additional_funcs.c ./libft/ft_more_ft_for_split.c

OBJS  = ${FT_PRINTF:.c=.o}
DEPS  = ${FT_PRINTF:.c=.d}
CC   = gcc

CFLAGS  = -Werror -Wextra -Wall -MMD

all:  $(NAME)

-include $(DEPS)

.c.o : 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME) : ${OBJS} Makefile
	ar rc $(NAME) ${OBJS} 
	ranlib $(NAME)

bonus: $(NAME)

so :        
	${CC} -shared -o libft.so ${OBJS} 

clean:
	rm -f ${OBJS}
	rm -f ${DEPS}
	
fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re :  fclean all

.PHONY:  all clean fclean re .c.o bonus