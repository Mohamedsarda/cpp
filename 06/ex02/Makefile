NAME = Base

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:%.cpp=%.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp Base.hpp A.hpp B.hpp C.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ) *_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all
