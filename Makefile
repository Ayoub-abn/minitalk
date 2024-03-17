NAME = server
NAME_2 = client

CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_itoa.c put_str.c server.c
SRCC =  ft_atoi.c ft_itoa.c put_str.c client.c

OBGS = $(SRCS:.c=.o)
OBGC = $(SRCC:.c=.o)

all : $(NAME) $(NAME_2)

$(NAME): $(OBGS)
	$(CC) $(CFLAGS) $(OBGS) -o $(NAME)

$(NAME_2): $(OBGC)
	$(CC) $(CFLAGS) $(OBGC) -o $(NAME_2)

clean:
	rm -f $(OBGS) $(OBGC)

fclean: clean
	rm -f $(NAME) $(NAME_2)

re: fclean all

