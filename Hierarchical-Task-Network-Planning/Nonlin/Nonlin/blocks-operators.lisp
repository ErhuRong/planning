;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;; Common Lisp NONLIN - University of Maryland at College Park 
;;;;
;;;; Version 1.2, 11/91
;;;; (email nonlin-users-request@cs.umd.edu for more info)
;;;; 
;;;; BLOCKS-OPERATORS.LISP: Blocks World Operators 
;;;;
;;;; History:

;; (note: in the current system, goals have to ground)

(setf *autocond* t)

(reset-schematable)  		;  clear out schema table


(opschema makeon
    :todo (on ?x ?y)
    :expansion (
		(step1 :goal (cleartop ?x))
		(step2 :goal (cleartop ?y))
		(step3 :action (puton ?x ?y))
	       )
    :orderings ( (step1 -> step3) ( step2 -> step3))
    
    :variables (?x ?y)
)
    

(opschema makeclear
	  :todo (cleartop ?x)
	  :expansion (
		      (step1 :goal (cleartop ?y))
		      (step2 :action (puton ?y ?z))
		      )
	  :orderings ((step1 -> step2))
	  :conditions (
		       (:use-when (on ?y ?x) :at step2)
		       (:use-when (cleartop ?z) :at step2)
		       (:use-when (not (equal ?z ?y)) :at step1)
		       (:use-when (not (equal ?x ?z)) :at step1)
		       )
	  :variables (?x ?y ?z)
	  )


(actschema puton
	   :todo (puton ?x ?y)
	   :expansion ( (step1 :primitive (puton-action ?x ?y)))
	   :conditions (
			(:use-when (cleartop ?x) :at step1)
			(:use-when (cleartop ?y) :at step1)
			(:use-only-for-query (on ?x ?z) :at step1)
		       )
	   :effects  (
		      (step1 :assert (on ?x ?y))
		      (step1 :assert (cleartop ?z))
		      (step1 :delete (cleartop ?y))
		      (step1 :delete (on ?x ?z))
		      )
	  :variables (?x ?y ?z)
          :duration 1 
	   )





