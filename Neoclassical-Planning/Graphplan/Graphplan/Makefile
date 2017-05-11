CC	=gcc -g2
FLAGS	= -Wall -ansi -fPIC
INC_PYTHON = -I /usr/include/python2.7

_graphplan.so: y.tab.o lex.yy.o graphplan.o utilities.o hash.o planner.o graphplan_wrap.o dummy.o
	gcc -shared -o $@ $^

graphplan_wrap.o: graphplan_wrap.c
		$(CC) $(FLAGS) $(INC_PYTHON) -c $^

graphplan.py graphplan_wrap.c: graphplan.i
			swig -python graphplan.i

graphplan: y.tab.o lex.yy.o graphplan.o utilities.o hash.o planner.o dummy.o
	$(CC) $(FLAGS) lex.yy.o y.tab.o hash.o utilities.o graphplan.o planner.o dummy.o -o graphplan

y.tab.o: y.tab.h graphplan.h
	$(CC) $(FLAGS) -c y.tab.c

lex.yy.o: y.tab.h graphplan.h
	$(CC) $(FLAGS) -c lex.yy.c

hash.o: graphplan.h
	$(CC) $(FLAGS) -c hash.c

graphplan.o: graphplan.h
	$(CC) $(FLAGS) -c graphplan.c

utilities.o: graphplan.h
	$(CC) $(FLAGS) -c utilities.c

planner.o: graphplan.h
	$(CC) $(FLAGS) -c planner.c

dummy.o: graphplan.h
	$(CC) $(FLAGS) -c dummy.c
