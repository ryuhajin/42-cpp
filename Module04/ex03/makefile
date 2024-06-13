CC = c++

CFLAG = -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

NAME = ex03

SRCS = main.cpp \
		MateriaSource.cpp \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		Character.cpp

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
