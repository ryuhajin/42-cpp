CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98

NAME = ex03

SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

INCS = -I/include Weapon.h HumanA.h HumanB.h

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
