NAME = Harl

SRC = main.cpp Harl.cpp
 
OBJ = $(SRC:%.cpp=%.o)



CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp ./Harl.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all