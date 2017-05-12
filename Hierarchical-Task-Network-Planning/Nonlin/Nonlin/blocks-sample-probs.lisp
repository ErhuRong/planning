;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;;    Application:  NONLIN
;;;;  Appl. Version:  1.3
;;;;     Appl. Date:  Oct. 1992
;;;;
;;;;           File:  BLOCKS-SAMPLE-PROBS.LISP
;;;;       Contents:  Sample Blocks World Problems
;;;;
;;;;                  Dept. of Computer Science, University of Maryland at College Park
;;;;                  email: nonlin-users-request@cs.umd.edu
;;;;
;;;;       Language:  Macintosh Common Lisp 2.0
;;;;
;;;;   Requirements:  package NONLIN, blocks-operators.lisp
;;;;
;;;;  History:
;;;;  Date      Who  Modification
;;;;  ---------------------------------------------------------------------------------   

;;;;  NOTE:  In current system, goals have to be ground.


(defun problem1 ()
    (world1)
    (plan1))

(defun 3bs ()
     (world2)
      (plan2))

(defun 3bs-phantom ()
    (funcall (get-problem :name '3bs-phantom :always '((cleartop table))
	:inputs '((on b c) (cleartop b) (on a table) (cleartop a))
	:goals '((on a b) (on b c))
    )))

(defun problem3 ()
     (world3)
     (plan1))

(defun world3 ()
  (store-init-ctxt '((on a table) (on b table) (on c b) (on d c) (on e a ) (cleartop d) 
                        (cleartop e))))
    
(defun world2 ()
    (store-always-ctxt 
	'((cleartop table)))
    (store-init-ctxt
	'((on a table) (on b table) (on c table)
	  (cleartop a) (cleartop b) (cleartop c)))
)

(defun plan2 ()
    (plan 3bs
	  (g1 :goal (on a b))
	  (g2 :goal (on b c))
    )
)

(defun 2bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on a table) (on b table) (cleartop a) (cleartop b)))
    (plan  2bs
	   (g1 :goal (on a b)))
)

(defun 4bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on a table) (on b table) (on c table) (on d table)
		       (cleartop a) (cleartop b) (cleartop c) (cleartop d)))
    (plan  4bs
	   (g1 :goal (on a b))
	   (g2 :goal (on b c))
	   (g3 :goal (on c d)))
)

(defun 4bs1 ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on a table) (on b c) (on c table) (on d table)
		       (cleartop a) (cleartop b) (cleartop d)))
    (plan  4bs1
	   (g1 :goal (on a b))
	   (g2 :goal (on b c))
	   (g3 :goal (on c d)))
)

(defun my-4bs-old ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on i table) (on k table) (cleartop i) (cleartop k)
		       (on j l) (cleartop j) (on l table)))
    (plan my-4bs
	 (g1 :goal (on l k))
	 (g2 :goal (on k j))
	 (g3 :goal (on j i))
    ))

(defun my-6bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on 2 table) (on 1 table) (cleartop 5) (cleartop 4)
		       (on 3 2) (on 5 3) (on 6 1) (on 4 6)))
    (plan my-6bs
	 (g1 :goal (on 1 2))
	 (g2 :goal (on 2 3))
	 (g3 :goal (on 3 table))
         (g4 :goal (on 5 6))
	 (g5 :goal (on 4 5))
         (g6 :goal (on 6 table))
    ))

(defun 15bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on 2 table) (on 1 table)(on 3 table)(on 4 table)
		       (cleartop 15) (cleartop 14)(cleartop 9)(cleartop 12)
		       (on 6 2) (on 7 3) (on 5 1) (on 15 4 )(on 8 5)(on 9 6)
		       (on 10 7)(on 11 8)(on 12 10)(on 13 11)(on 14 13)))
    (plan 15bs
	 (g1 :goal (on 1 2))
	 (g2 :goal (on 2 3))
         (g3 :goal (on 3 4))
         (g4 :goal (on 4 5))
	 (g5 :goal (on 5 6))
	 (g6 :goal (on 15 14))
	 (g7 :goal (on 14 13))
         (g8 :goal (on 13 12))
	 (g9 :goal (on 12 11))
	 (g10 :goal (on 11 10))
	 (g11 :goal (on 9 1))
         (g12 :goal (on 8 15))
	 (g13 :goal (on 7 table))
    ))

(defun my-4bs1 ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on 2 table) (on 4 table) (cleartop 1) (cleartop 3)
		       (on 3 2) (on 1 4)))
    (plan my-4bs1
	 (g1 :goal (on 1 2))
	 (g2 :goal (on 2 table))
	 (g3 :goal (on 3 4))
         (g4 :goal (on 4 table))
    ))

(defun my-6bs1 ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on 2 table) (on 4 table) (cleartop 5) (cleartop 1)
		       (on 3 2) (on 5 3) (on 1 6) (on 6 4)))
    (plan my-6bs
	 (g1 :goal (on 1 2))
	 (g2 :goal (on 2 3))
         (g3 :goal (on 5 6))
	 (g4 :goal (on 4 5))
    ))

(defun my-5bs1 ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on 1 table) (on 5 table) (cleartop 2) (cleartop 4)
		       (on 3 1) (on 2 3) (on 4 5)))
    (plan my-5bs1
	 (g1 :goal (on 1 2))
	 (g2 :goal (on 2 3))
	 (g3 :goal (on 3 4))
         (g4 :goal (on 4 5))
    ))

(defun my-4bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on i table) (on k table) (cleartop i) (cleartop k)
		       (on j l) (cleartop j) (on l table)))
    (plan my-4bs
	 (g1 :goal (on j i))
	 (g2 :goal (on k j))
	 (g3 :goal (on l k))
    ))

(defun suss-4bs ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on j table) (on l table) (cleartop j) (cleartop l)
		       (on k i) (cleartop k) (on i table)))
    (plan suss-4bs
	 (g1 :goal (on j i))
	 (g2 :goal (on k j))
	 (g3 :goal (on l k))
    ))

(defun suss-4bs-old ()
    (store-always-ctxt '((cleartop table)))
    (store-init-ctxt '((on j table) (on l table) (cleartop j) (cleartop l)
		       (on k i) (cleartop k) (on i table)))
    (plan suss-4bs
	 (g1 :goal (on l k))
	 (g2 :goal (on k j))
	 (g3 :goal (on j i))
    ))

(defun nonlin-blocks ()
     (store-always-ctxt '((cleartop table)))
     (store-init-ctxt '((on a b) (on b table) (on c table) (on d table)
                        (cleartop a)  (cleartop c) (cleartop d)))
     (plan nonlin-blocks
	  (g1 :goal (on a b))
	  (g2 :goal (on b c))
    ))
    
(defun sussman-blocks ()
     (store-always-ctxt '((cleartop table)))
     (store-init-ctxt '((on a c) (on c table) (on b table)
                        (cleartop a) (cleartop b) ))
     (plan  sussman-blocks
	  (g1 :goal (on a b))
	  (g2 :goal (on b c))
    ))

(defun noah-blocks ()
         (store-always-ctxt '((cleartop table)))
     (store-init-ctxt '((on a table) (on b table) (on c a) (on d b)
                        (cleartop c) (cleartop d)))
     (plan noah-blocks
	   (g1 :goal (on a b))
            (g2 :goal (on b c))
             (g3 :goal (on c d)))
)

(defun plan1 ()
    (plan problem1 (g1 :goal (on a b))))    
    
(defun world1 ()
    (store-always-ctxt 
	'((cleartop table)))
    (store-init-ctxt
	'((on a table) (on b table) (on c b)
	  (cleartop a)  (cleartop c)))
)
    
