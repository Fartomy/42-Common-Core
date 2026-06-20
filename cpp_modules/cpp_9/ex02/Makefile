NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS= $(SRCS:.cpp=.o)
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
CC= c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o $(NAME)

clean: 
	rm -rf $(NAME) $(OBJS)

re: clean $(NAME)
.PHONY : all clean re