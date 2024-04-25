CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98 -g $(SANITIZE)

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	 $(CC) $(CFLAG) -c $^ -o $@

clean : 
		rm -rf $(OBJS)

fclean : clean 
	    rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
