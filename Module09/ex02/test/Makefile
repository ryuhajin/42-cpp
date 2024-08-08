CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP -g3

NAME = PmergeMeT

SRCS = main_test.cpp \
		PmergeMe_test.cpp

INCS = -I.

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:%.o=%.d)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME) 

%.o : %.cpp
	 $(CC) $(CFLAG) $(INCS) -c $< -o $@

clean : 
		rm -rf $(OBJS) $(DEPS)

fclean : clean 
	    rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEPS)
