NAME = Bureaucrat
CPP= c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM= rm -rf
HEADERS= Bureaucrat.hpp
SRC= main.cpp Bureaucrat.cpp
OBJ= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CPP) $(CPPFLAGS) -o $@ $(OBJ)
		@echo "program named $@ has been created successfully"
%.o : %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "the file $@ has been created from $<"

clean:
		@$(RM) $(OBJ)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean re
 