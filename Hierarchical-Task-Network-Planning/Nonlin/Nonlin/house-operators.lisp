;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;; Common Lisp NONLIN - University of Maryland at College Park 
;;;;
;;;; Version 1.2, 11/91
;;;; (email nonlin-users-request@cs.umd.edu for more info)
;;;; 
;;;; HOUSE-OPERATORS.LISP: House-Building Domain Operators (Tate's Sample Domain) 
;;;;
;;;; History:

(in-package :common-lisp-user)

;;; (include :unsuperv conds - see Fix #1 description)

(setf *autocond* t)

(actschema build
  :todo (build house)
  :expansion (
              (step1 :action (excavate  pour footers       ))
              (step2 :action (pour concrete foundations    ))
              (step3 :action (erect frame and roof         ))
              (step4 :action (lay brickwork                ))
              (step5 :action (finish roofing and flashing  ))
              (step6 :action (fasten gutters and downspouts))
              (step7 :action (finish grading               ))
              (step8 :action (pour walks  landscape        ))
              (step9 :action (install services             ))
              (step10 :action (decorate                    ))
             )
  :orderings ( (step1 -> step2) (step2 -> step3) (step3 -> step4) (step4 -> step5)
               (step5 -> step6) (step6 -> step7) (step7 -> step8) 
             )
  :conditions (
               (:precond  (footers poured        ) :at step2 :from step1)
               (:precond  (foundations laid      ) :at step3 :from step2)
               (:precond  (frame and roof erected) :at step4 :from step3)
               (:precond  (brickwork done        ) :at step5 :from step4)
               (:precond  (roofing finished      ) :at step6 :from step5)
               (:precond  (gutters etc fastened  ) :at step7 :from step6)
               (:unsuperv (storm drains laid     ) :at step7)
               (:precond  (grading done          ) :at step8 :from step7)
              )
)
  
(actschema service
  :todo (install services)
  :expansion (
              (step1 :action (install drains           ))
              (step2 :action (lay storm drains         ))
              (step3 :action (install rough plumbing   ))
              (step4 :action (install finished plumbing))
              (step5 :action (install rough wiring     ))
              (step6 :action (finish electrical work   ))
              (step7 :action (install kitchen equipment))
              (step8 :action (install air conditioning ))
             )
  :orderings ((step1 -> step3) (step3 -> step4) (step5 -> step6) 
              (step3 -> step7) (step5 -> step7))
  :conditions (
               (:precond  (drains installed        ) :at step3 :from step1)
               (:precond  (rough plumbing installed) :at step4 :from step3)
               (:precond  (rough wiring installed  ) :at step6 :from step5)
               (:precond  (rough plumbing installed) :at step7 :from step3)
               (:precond  (rough wiring installed  ) :at step7 :from step5)
               (:unsuperv (foundations laid        ) :at step1)
               (:unsuperv (foundations laid        ) :at step2)
               (:unsuperv (frame and roof erected  ) :at step5)
               (:unsuperv (frame and roof erected  ) :at step8)
               (:unsuperv (basement floor laid     ) :at step8)
               (:unsuperv (flooring finished       ) :at step4)
               (:unsuperv (flooring finished       ) :at step7)
               (:unsuperv (painted                 ) :at step6)
              )
)
           
(actschema decor
  :todo (decorate)
  :expansion (
              (step1 :action (fasten plaster and plaster board))
              (step2 :action (pour basement floor             ))
              (step3 :action (lay finished flooring           ))
              (step4 :action (finish carpentry                ))
              (step5 :action (sand and varnish floors         )) 
              (step6 :action (paint                           ))

             )
  :orderings ( (step2 -> step3) (step3 -> step4) (step4 -> step5)
               (step1 -> step3)  (step6 -> step5))
  :conditions (
               (:unsuperv (rough plumbing installed   ) :at step1)
               (:unsuperv (rough wiring installed     ) :at step1)
               (:unsuperv (air conditioning installed ) :at step1)
               (:unsuperv (drains installed           ) :at step2)
               (:unsuperv (plumbing finished          ) :at step6)
               (:unsuperv (kitchen equipment installed) :at step6)
               (:precond  (plastering finished        ) :at step3 :from step1)
               (:precond  (basement floor laid        ) :at step3 :from step2)
               (:precond  (flooring finished          ) :at step4 :from step3)
               (:precond  (carpentry finished         ) :at step5 :from step4)
               (:precond  (painted                    ) :at step5 :from step6)
              )
)
              
(actschema excavate
  :todo (excavate pour footers)
  :expansion (
              (step1 :primitive (excavate and pour footers))
             )
  :effects   ( 
              (step1 :assert (footers poured))
             )
)

(actschema pour-concrete
  :todo (pour concrete foundations)
  :expansion (
              (step1 :primitive (pour the concrete foundations))
             )
  :effects   ( 
              (step1 :assert (foundations laid))
             )
)

(actschema erect-frame
  :todo (erect frame and roof)
  :expansion (
              (step1 :primitive (erect the frame and roof))
             )
  :effects   ( 
              (step1 :assert (frame and roof erected))
             )
)

(actschema brickwork
  :todo (lay brickwork)
  :expansion (
              (step1 :primitive (lay the brickwork))
             )
  :effects   ( 
              (step1 :assert (brickwork done))
             )
)

(actschema finish-roofing
  :todo (finish roofing and flashing)
  :expansion (
              (step1 :primitive (finish the roofing and flashing))
             )
  :effects   ( 
              (step1 :assert (roofing finished))
             )
)

(actschema fasten-gutters
  :todo (fasten gutters and downspouts)
  :expansion (
              (step1 :primitive (fasten the gutters and downspouts))
             )
  :effects   ( 
              (step1 :assert (gutters etc fastened))
             )
)

(actschema finish-grading
  :todo (finish grading)
  :expansion (
              (step1 :primitive (finish the grading))
             )
   :effects   ( 
              (step1 :assert (grading done))
             )
)

(actschema pour-walks
  :todo (pour walks landscape)
  :expansion (
              (step1 :primitive (pour walks and landscape))
             )
  :effects   ( 
              (step1 :assert (landscaping done))
             )
)

(actschema install-drains
  :todo (install drains)
  :expansion (
              (step1 :primitive (install the drains))
             )
  :effects   ( 
              (step1 :assert (drains installed))
             )
)

(actschema lay-storm
  :todo (lay storm drains)
  :expansion (
              (step1 :primitive (lay the storm drains))
             )
  :effects   ( 
              (step1 :assert (storm drains laid))
             )
)

(actschema rough-plumbing
  :todo (install rough plumbing)
  :expansion (
              (step1 :primitive (install the rough plumbing))
             )
  :effects   ( 
              (step1 :assert (rough plumbing installed))
             )
)

(actschema install-finished
  :todo (install finished plumbing)
  :expansion (
              (step1 :primitive (install the finished plumbing))
             )
  :effects   ( 
              (step1 :assert (plumbing finished))
             )
)

(actschema rough-wiiring
  :todo (install rough wiring)
  :expansion (
              (step1 :primitive (install the rough wiring))
             )
  :effects   ( 
              (step1 :assert (rough wiring installed))
             )
)

(actschema finish-electrical
  :todo (finish electrical work)
  :expansion (
              (step1 :primitive (finish the electrical work))
             )
  :effects   ( 
              (step1 :assert (electrical work finished))
             )
)

(actschema install-kitchen
  :todo (install kitchen equipment)
  :expansion (
              (step1 :primitive (the kitchen equipment installed))
             )
  :effects   ( 
              (step1 :assert (kitchen equipment installed))
             )
) 

(actschema install-air
  :todo (install air conditioning)
  :expansion (
              (step1 :primitive (install the air conditioning))
             )
  :effects   ( 
              (step1 :assert (air conditioning installed))
             )
)

(actschema fasten-plaster
  :todo (fasten plaster and plaster board)
  :expansion (
              (step1 :primitive (fasten the plaster and plaster-board))
             )
  :effects   ( 
              (step1 :assert (plastering finished))
             )
)

(actschema pour-basement
  :todo (pour basement floor)
  :expansion (
              (step1 :primitive (pour the basement floor))
             )
  :effects   ( 
              (step1 :assert (basement floor laid))
             )
)

(actschema lay-flooring
  :todo (lay finished flooring)
  :expansion (
              (step1 :primitive (lay the finished flooring))
             )
  :effects   ( 
              (step1 :assert (flooring finished))
             )
)

(actschema finish-garden
  :todo (finish garden)
  :expansion (
              (step1 :primitive (finish the garden))
             )
  :effects   ( 
              (step1 :assert (garden finished))
             )
)

(actschema finish-carpentry
  :todo (finish carpentry)
  :expansion (
              (step1 :primitive (finish the carpentry))
             )
  :effects   ( 
              (step1 :assert (carpentry finished))
             )
)

(actschema  sand
  :todo (sand and varnish floors) 
  :expansion (
              (step1 :primitive (sand and varnish the floors))
             )
  :effects   ( 
              (step1 :assert (floors varnished))
             )
)

(actschema paint
  :todo (paint)
  :expansion (
              (step1 :primitive (complete painting))
             )
  :effects   ( 
              (step1 :assert (painted))
             )
)





