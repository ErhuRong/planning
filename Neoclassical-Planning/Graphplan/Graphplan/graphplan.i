%module graphplan

%include <argcargv.i>

%{
#define SWIG_GRAPHPLAN
#include "graphplan.h"
%}

%apply (int ARGC, char **ARGV) { (int argc, char *argv[]) }

int oldmain(int argc, char *argv[]);


