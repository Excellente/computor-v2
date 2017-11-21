CC		= clang++
CFLAGS	= -std=c++11
EXE		= computorv2
INC 	= ./include/
SRC 	= main.cpp polynom/computor.cpp polynom/term.cpp input/syntax.cpp	\
		  input/lexer.cpp input/map.cpp input/iostream.cpp eval/btree.cpp 	\
		  eval/var.cpp

SRCDIR 	= ./src/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
LIBDIR	= $(SRCDIR)lib/
LIBOBJ	= ./obj/
LIBSRC	= $(wildcard $(LIBDIR)*.cpp)
LIB		= libstr.a

all: $(LIB)
	$(CC) $(CFLAGS) $(SRCS) -L. $(LIB) -I $(INC) -o $(EXE)

$(LIB): $(LIBOBJ)
	ar rc $(LIB) $(LIBOBJ)*.o
	ranlib $(LIB)

$(LIBOBJ):
	$(CC) $(CFLAGS) -c $(LIBSRC) -I $(INC)
	@mkdir $@; mv *.o $@

clean:
	rm -f $(EXE) *.out *.o

fclean: clean
	rm -fr $(LIB) $(LIBOBJ)

push: fclean
	git add .
	git commit -m "automated push"
	git push origin master

re: fclean all
