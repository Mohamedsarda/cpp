NAME = Form

SRC = AForm.cpp Bureaucrat.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:%.cpp=%.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp AForm.hpp Bureaucrat.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ) *_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all
