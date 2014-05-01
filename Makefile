NAME=myminishell
SRC=minishell.c
LIBPATH=../lib
LIB=my
RM=rm -f
all:$(SRC)
	cc -L$(LIBPATH) $(SRC) -l$(LIB) -o $(NAME)
clean:
	-$(RM) $(NAME)
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.swp
fclean:clean
re:fclean all
