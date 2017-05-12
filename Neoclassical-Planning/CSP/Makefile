#CC = g++ -g2 -O2 -fconserve-space -fnonnull-objects -Wall
CC	= gcc -g2 -fPIC
PFLAGS = -lfl
FLAGS	= -Wall -ansi

INC_PYTHON = -I/usr/include/python2.7

#OBJS = y.tab.o lex.yy.o graphplan.o utilities.o hash.o planner.o dummy.o 
OBJS = bbpddl.tab.o graphplan.o utilities.o hash.o planner.o dummy.o justify.o lex.yy.o

_gpcsp.so: $(OBJS) gpcsp_wrap.o
	gcc -shared -o $@ $^ csp/*.o Share/csp.o Share/debug.o Share/limit.o Share/stack.o Share/timer.o Share/solve_GAC_CBJ.o Share/ebl.o

gpcsp_wrap.o: gpcsp_wrap.c
	$(CC) -c $(FLAGS) $(INC_PYTHON) $^

gpcsp_wrap.c gpcsp.py: gpcsp.i
	swig -python gpcsp.i

gpcsp: $(OBJS)
	cd csp; make
	cd Share; make
	$(CC) $(FLAGS) $(OBJS) $(PFLAGS) csp/*.o Share/csp.o Share/debug.o Share/limit.o Share/stack.o Share/timer.o Share/solve_GAC_CBJ.o Share/ebl.o -o gpcsp 

#y.tab.o: y.tab.h graphplan.h 
bbpddl.tab.c: bbpddl.y lex.yy.c
	bison -d bbpddl.y

bbpddl.tab.o: bbpddl.tab.c graphplan.h 

lex.yy.c: bbpddl.l
	flex bbpddl.l

#lex.yy.o: y.tab.h graphplan.h
lex.yy.o: graphplan.h bbpddl.tab.h

hash.o: graphplan.h

graphplan.o: graphplan.h

utilities.o: graphplan.h

planner.o: graphplan.h

justify.o: justify.h graphplan.h

clean:
	cd csp; make clean
	cd Share; make clean
	/bin/rm *.o lex*.c *.tab.c gpcsp 
