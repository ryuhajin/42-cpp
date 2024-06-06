CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP

NAME = ex01

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

INCS = -I.

OBJS = $(SRCS:.cpp=.o)

MMD = $(SRCS:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.cpp
	 $(CC) $(CFLAG) $(INCS) -c $^ -o $@

clean : 
		rm -rf $(OBJS) $(MMD)

fclean : clean 
	    rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
