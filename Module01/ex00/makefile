CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98

NAME = ex00

SRCS = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

INCS = -I/include Zombie.h

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	 $(CC) $(CFLAG) $(INCS) -c $^ -o $@

clean : 
		rm -rf $(OBJS)

fclean : clean 
	    rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
