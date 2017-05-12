;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;;    Application:  NONLIN/PRIAR
;;;;  Appl. Version:  1.2.2
;;;;     Appl. Date:  Oct. 1992
;;;;
;;;;           File:  NONLIN-PACKAGE.LISP
;;;;       Contents:  PACKAGE DEFINITION
;;;;
;;;;                  Copyright (C) 1992.
;;;;                  Dept. of Computer Science, University of Maryland at College Park
;;;;                  email: nonlin-users-request@cs.umd.edu
;;;;
;;;;       Language:  Macintosh Common Lisp 2.0
;;;;
;;;;   Requirements:  
;;;;
;;;;  History:
;;;;  Date      Who  Modification
;;;;  ---------------------------------------------------------------------------------   
;;;;  12/10/93  bpk  modified for PRIAR
;;;;   7/28/93  bpk  added READSCHEMA
;;;;   7/27/93  bpk  fixed bug
;;;;  11/22/92  bpk  fixed various compile time probs. by adding misc. eval-when's

(in-package :cl-user)

(defpackage :nonlin
    (:use :common-lisp) ; :ccl = :lisp
    (:export 
     ;; GLOBAL VARS:
     "*CURRENT-NONLIN-VERSION*"
     "*CURRENT-NONLIN-VERSION-DATE*"
     "*NONLIN-LOADED-P*"
     "*NONLIN-OPS-LOADED*"
     "*NONLIN-USE-MODE*"
     "*CYCLE-COUNT*"
     "*CYCLE-LIMIT*"
     "*PLANNER-IN*"
     "*PLANNER-OUT*"
     "*PLANNER-EXPANSIONS*"
     "*ALWAYS-CTXT-NODE-ID*"            
     "*INIT-CTXT-NODE-ID*"             
     "*PLAN-HEAD-NODE-ID*"             
     "*GOALS*"
     "*PLANSCHEMA*"
     "*NONLIN-TERMIN-STATUS*"
     "*INIT-CTXT*"
     "*ALWAYS-CTXT*"
     "*AUTOCOND*"
     "*DEVISOR-MODS*"
     "*TIME0*"
     "*INFINITY*"

     ;; FUNCTION NAMES:
     "PLAN-FOR"
     "NONLIN-DEBUG"
     "NONLIN-UNDEBUG"
     "NONLIN-DEBUG-OPTIONS"
     "STORE-ALWAYS-CTXT"
     "STORE-INIT-CTXT"
     "GET-PROBLEM"
     "PRINT-ALLNODES"
     "PRINT-TOME"
     "PRINT-GOST"
     "PRINT-TASKQUEUE"
     "RESET-SCHEMATABLE"
     "DUMP-SCHEMATABLE"
     "READSCHEMA"
     
     ;; MACRO NAMES:
     "ACTSCHEMA"
     "OPSCHEMA"
     "PLAN"

     "->"
     "<-"
))
