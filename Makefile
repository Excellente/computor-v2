CC		= clang++
CFLAGS	= -std=c++11
EXE		= computorv2
INC 	= ./include/
SRC 	= main.cpp polynom/computor.cpp polynom/term.cpp input/syntax.cpp\
		  input/lexer.cpp input/map.cpp
SRCDIR 	= ./src/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))

all:
	$(CC) $(CFLAGS) $(SRCS) -I $(INC) -o $(EXE)

clean:
	rm -f $(EXE) *.out

push: clean
	git add .
	git commit -m "automated push"
	git push origin master

re: clean all
