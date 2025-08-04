sources = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

objects = $(sources:.cpp=.o)

cc = c++

cflags = -Wall -Wextra -Werror -std=c++98

NAME = forms

$(NAME): $(objects)
	$(cc) $(cflags) -o $(NAME) $(objects)

all: $(NAME)

%.o: %.cpp
	$(cc) $(cflags) -c $< -o $@

clean:
	rm -f ${objects}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
