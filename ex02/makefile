CXX			:=	c++
CXXFLAGS	:=	-g -Wall -Wextra -Werror -std=c++98
OBJFLAGS 	:=	-c

NAME		:=	PmergeMe

SRCS_F		:= 	main \
				PmergeMe

SRCS		:=	$(addsuffix .cpp, $(SRCS_F))
OBJ			:=	$(addsuffix .o, $(SRCS_F))

DEP			:= Makefile PmergeMe.hpp

all: 		$(NAME)

%.o:		%.cpp $(DEP)
				$(CXX) $(CXXFLAGS) $(OBJFLAGS) $< -o $@ -I.

$(NAME):	$(OBJ)
				$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
				@rm -f $(OBJ)

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re