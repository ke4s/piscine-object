SRCS = main.cpp Accounts.cpp Bank.cpp

FLAGS = c++ -Wall -Wextra -Werror -std=c++98 

NAME = bank

all : $(NAME)

$(NAME) : $(SRCS)
		$(FLAGS) $(SRCS) -o $(NAME)

clean :
		rm -f $(NAME)

fclean : clean
		@echo cleaning 100%

re : fclean all

.Phony : clean fclean all re