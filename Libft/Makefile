NAME = libft.a
CC = cc
FLAGS = -g3 -Wall -Wextra -Werror
AR = ar rcs

SRC = \
		ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memcpy \
		ft_memset \
		ft_strlen \
		ft_memmove \
		ft_strlcpy \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_strlcat \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstadd_back \
		ft_lstsize \
		ft_lstlast \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \
		ft_reductitron \
		ft_demolitron \
		ft_atol \
		coloured_write \
		ft_printf \
		ft_iputnum_ptr \
		ft_iputnums \
		ft_iputptr \
		ft_iputchar \
		ft_iputchar \
		ft_iputstr \
		ft_toupper \
		get_next_line \
		ft_strchr \
		ft_strdup \
		ft_strlen \
		ft_strchr \
		ft_bzero

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

.c.o:
	$(CC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
		rm -f *.o

fclean: clean 
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fc re