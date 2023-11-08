NAME=clapTrap
CPP= c++ 
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
RM=rm -f
SRC = ClapTrap.cpp  main.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) -o $@ $(OBJ)
		@echo "the files has ben archived successfully"

%.o: %.cpp ClapTrap.hpp
		@$(CPP) $(CPPFLAGS) -o $@ -c $<
		@echo "the file $@ has been created from $<"


clean:
		@$(RM) $(OBJ)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the $(NAME) has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean re
