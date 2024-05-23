CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME = ex02

SRCS = main.cpp \
		Fixed.cpp

INCS = -I Fixed.h

OBJS = $(SRCS:.cpp=.o)

MMD = $(SRCS:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME) $(INCS)

%.o : %.cpp
	 $(CC) $(CFLAG) -c $^ -o $@

clean : 
		rm -rf $(OBJS) $(MMD)

fclean : clean 
	    rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
