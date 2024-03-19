NAME = server
NAME_2 = client
NAME_3 = server_bonus
NAME_4 = client_bonus

CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_itoa.c put_str.c server.c
SRCC =  ft_atoi.c ft_itoa.c put_str.c client.c
SRCSB = ft_atoi.c ft_itoa.c put_str.c server_bonus.c
SRCCB =  ft_atoi.c ft_itoa.c put_str.c client_bonus.c
OBGS = $(SRCS:.c=.o)
OBGC = $(SRCC:.c=.o)
OBGSB = $(SRCSB:.c=.o)
OBGCB = $(SRCCB:.c=.o)
all : $(NAME) $(NAME_2)

$(NAME): $(OBGS)
	$(CC) $(CFLAGS) $(OBGS) -o $(NAME)

$(NAME_2): $(OBGC)
	$(CC) $(CFLAGS) $(OBGC) -o $(NAME_2)

bonus : $(NAME_3) $(NAME_4)

$(NAME_3): $(OBGSB)
	$(CC) $(CFLAGS) $(OBGSB) -o $(NAME_3)

$(NAME_4): $(OBGCB)
	$(CC) $(CFLAGS) $(OBGCB) -o $(NAME_4)
clean:
	rm -f $(OBGS) $(OBGC) $(OBGSB) $(OBGCB) 

fclean: clean
	rm -f $(NAME) $(NAME_2) $(NAME_3) $(NAME_4)  

re: fclean all

