;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;;    Application:  UM Nonlin 1.3
;;;;
;;;;           File:  UMT-LOAD-METHODS-NL.LISP
;;;;       Contents:  Nonlin schema defns for Load/Unload Methods in the UM-Translog domain.
;;;;
;;;;         Author:  K. Erol, B. Kettler
;;;;                  (c) Dept. of Computer Science, University of Maryland at College Park
;;;;
;;;;       Language:  Macintosh Common Lisp 2.0
;;;;
;;;;   Requirements:  Files loaded in order: 1) UMT-MAIN-METHODS-NL
;;;;                                         2) UMT-LOAD-METHODS-NL
;;;;                                         3) UMT-ACTIONS-NL
;;;;
;;;;  History:
;;;;  Date      Who  Modification
;;;;  -----------------------------------------------------------------------------------   
;;;;   6/06/95  bpk  replaced (UN)LOAD-VALUABLE with (UN)LOAD-VAL, (UN)LOAD-HAZ-VAL.
;;;;                 added LOAD-TOP, UNLOAD-TOP
;;;;   6/06/95  ke   replaced (UN)LOAD-HAZARDOUS with (UN)LOAD-HAZ, (UN)LOAD-HAZ-NOT,
;;;;   6/05/95       changed package specifier and commented out lines,
;;;;                 fixed errors in LOAD-VEHICLE-AUTO, UNLOAD-VEHICLE-AUTO, LOAD-AIRPLANE, 
;;;;                 UNLOAD-AIRPLANE
;;;;   7/18/94       replaced :use-only-for-query conditions with :use-when conditions
;;;;   6/21/94       created

(setq *autocond* nil)

;;; --------------------------------------------------------------------------------------

;;; TOP-LEVEL LOAD METHOD
(opschema load-top
          :todo (load-top ?p ?v ?l)
          :expansion (
                      (s1 :action (load-haz ?p ?v ?l))
                      (s2 :action (load-val ?p ?v ?l)) ; invokes load
                     )
          :orderings ((-> s1 s2))
          :variables (?p ?v ?l)
)

;;; TOP-LEVEL UNLOAD METHOD
(opschema unload-top
          :todo (unload-top ?p ?v ?l)
          :expansion (
                      (s1 :action (unload-val ?p ?v ?l)) ; invokes unload
                      (s2 :action (unload-haz ?p ?v ?l))
                     )
          :orderings ((-> s1 s2))
          :variables (?p ?v ?l)
)

;;; --------------------------------------------------------------------------------------

;;; LOAD A HAZARDOUS PACKAGE
(opschema load-haz
          :todo (load-haz ?p ?v ?l)
          :expansion (
                      (s1 :goal (warning-signs-affixed ?p ?v))
                     )
          :conditions ((:use-when (type ?p hazardous) :at s1))
          :variables  (?p ?v ?l)
)

;;; LOAD A NONHAZARDOUS PACKAGE
(opschema load-not-haz
          :todo (load-haz ?p ?v ?l)
          :expansion (
                      (s1 :primitive (do-nothing))
                     )
          :conditions ((:use-when (type ?p not-hazardous) :at s1))
          :variables  (?p ?v ?l)
)

;;; UNLOAD A HAZARDOUS PACKAGE
(opschema unload-haz
          :todo (unload-haz ?p ?v ?l)
          :expansion (
                      (s1 :goal (decontaminated-interior ?v))
                      (s2 :goal (warning-signs-removed ?p ?v))
                     )
          :orderings  ((-> s1 s2))
          :conditions ((:use-when (type ?p hazardous) :at s1))
          :variables  (?p ?v ?l)
)

;;; UNLOAD A NONHAZARDOUS PACKAGE
(opschema unload-not-haz
          :todo (unload-haz ?p ?v ?l)
          :expansion (
                      (s1 :primitive (do-nothing))
                     )
          :conditions ((:use-when (type ?p not-hazardous) :at s1))
          :variables  (?p ?v ?l)
)

;;; --------------------------------------------------------------------------------------

;;; LOAD A VALUABLE PACKAGE
(opschema load-val
          :todo (load-val ?p ?v ?l)
          :expansion (
                      (s1 :goal   (guard-outside ?v))
                      (s2 :action (load ?p ?v ?l))
                      (s3 :goal   (guard-inside  ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions ((:use-when (type ?p valuable) :at s1))
          :variables  (?p ?v ?l)
)

;;; LOAD A NONVALUABLE PACKAGE
(opschema load-not-val
          :todo (load-val ?p ?v ?l)
          :expansion (
                      (s1 :action (load ?p ?v ?l))
                     )
          :conditions ((:use-when (type ?p not-valuable) :at s1))
          :variables  (?p ?v ?l)
)

;;; UNLOAD A VALUABLE PACKAGE
(opschema unload-val
          :todo (unload-val ?p ?v ?l)
          :expansion (
                      (s1 :goal   (guard-outside ?v))
                      (s2 :action (unload ?p ?v ?l))
                     )
          :orderings ((-> s1 s2))
          :conditions ((:use-when (type ?p valuable) :at s1))
          :variables  (?p ?v ?l)
)

;;; UNLOAD A NONVALUABLE PACKAGE
(opschema unload-not-val
          :todo (unload-val ?p ?v ?l)
          :expansion (
                      (s1 :action (unload ?p ?v ?l))
                     )
          :conditions ( (:use-when (type ?p not-valuable) :at s1))
          :variables (?p ?v ?l)
)

;----------------------------------------------------------------------------------------

;;; method for loading REGULAR truck or traincar
(opschema load-regular-vehicle        
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (door-open ?v))
                      (s2 :action (do-load-package ?p ?v))
                      (s3 :goal   (door-closed ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v regular)  :at s1)
                       (:use-when (at-package ?p ?l) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?l) :at s2)
                       (:precond  (at-package ?p ?v) :from s2 :at s3)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (door-open  ?v)    :from s1 :at s3) 
                      )
          :variables (?p ?v ?l)
)

;;; method for unloading REGULAR truck or traincar
(opschema unload-regular-vehicle        
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (door-open ?v))
                      (s2 :action (do-unload-package ?p ?v))
                      (s3 :goal   (door-closed ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v regular)  :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?v) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:use-when (at-package ?p ?v) :at s2)
                       (:precond  (door-open  ?v)    :from s1 :at s3)
                      )
          :variables (?p ?v ?l)
)

;;; --------------------------------------------------------------------------------------

;;; method for loading FLATBED truck or traincar
(opschema load-flatbed-vehicle  
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :action (do-pick-up-package-ground   ?p ?c))
                      (s2 :action (do-put-down-package-vehicle ?p ?c ?v))
                     )
          :orderings ((-> s1 s2))
          :conditions (
                       (:use-when (type ?v flatbed)    :at s1)
                       (:use-when (type ?c crane)      :at s1)
                       (:use-when (empty ?c)           :at s1) ; ???
                       (:use-when (at-package   ?p ?l) :at s1)
                       (:use-when (at-equipment ?c ?l) :at s1)
                       (:precond  (at-package   ?p ?c) :from s1 :at s2)
                       (:use-when (at-vehicle   ?v ?l) :at s2)
                       (:use-when (at-equipment ?c ?l) :at s2) ; ???
                      )
          :effects ( (s2 :assert (empty ?c) ))
          :variables (?p ?v ?l ?c)
)

;;; method for unloading FLATBED truck or traincar
(opschema unload-flatbed-vehicle  
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :action (do-pick-up-package-vehicle  ?p ?c ?v))
                      (s2 :action (do-put-down-package-ground ?p ?c))
                     )
          :orderings ((-> s1 s2))
          :conditions (
                       (:use-when (type ?v flatbed)    :at s1)                     
                       (:use-when (at-package   ?p ?v) :at s1)
                       (:use-when (at-vehicle   ?v ?l) :at s1)
                       (:use-when (at-equipment ?c ?l) :at s1)
                       (:use-when (type ?c crane)      :at s1)
                       (:use-when (empty ?c)           :at s1) ; ???
                       (:precond  (at-package   ?p ?c) :from s1 :at s2)
                       (:use-when (at-equipment ?c ?l) :at s2) ; ???
                      )
          :effects ( (s2 :assert (empty ?c) ))
          :variables (?p ?v ?l ?c)
)

;;; method for loading HOPPER truck or traincar
(opschema load-hopper-vehicle 
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (chute-connected ?v))
                      (s2 :action (do-fill-hopper ?p ?v))
                      (s3 :goal   (chute-disconnected ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v hopper)   :at s1)
                       (:use-when (at-package ?p ?l) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?l) :at s2)
                       (:precond  (at-package ?p ?v) :from s2 :at s3)
                       (:use-when (at-vehicle ?v ?l)   :at s3)
                       (:precond  (chute-connected ?v) :from s1 :at s3)
                      )
          :variables (?p ?v ?l)
)

;;; method for unloading HOPPER truck or traincar
(opschema unload-hopper-vehicle 
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (chute-connected ?v))
                      (s2 :action (do-empty-hopper ?p ?v))
                      (s3 :goal   (chute-disconnected ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v hopper)   :at s1)
                       (:use-when (at-package ?p ?v) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?v) :at s2)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (chute-connected ?v) :from s1 :at s3)
                      )
          :variables (?p ?v ?l)
)


;;; method for loading TANKER truck or traincar
(opschema load-tanker-vehicle 
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (hose-connected ?v ?p))
                      (s2 :goal   (valve-open ?v))
                      (s3 :action (do-fill-tank ?v ?p))
                      (s4 :goal   (valve-closed ?v))
                      (s5 :goal   (hose-disconnected ?v))
                     )
          :orderings ((-> s1 s2 s3 s4 s5))
          :conditions (
                       (:use-when (type ?v tanker)   :at s1)
                       (:use-when (at-package ?p ?l) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?l) :at s2)
                       (:precond  (at-package ?p ?v) :from s2 :at s3)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (hose-connected ?v ?p) :from s1 :at s5)
                       (:precond  (valve-open     ?v)    :from s2 :at s4)
                      )
          :variables (?p ?v ?l)
)

;;; method for unloading TANKER truck or traincar
(opschema unload-tanker-vehicle 
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (hose-connected ?v ?p))
                      (s2 :goal   (valve-open ?v))
                      (s3 :action (do-empty-tank ?v ?p))
                      (s4 :goal   (valve-closed ?v))
                      (s5 :goal   (hose-disconnected ?v))
                     )
          :orderings ((-> s1 s2 s3 s4 s5))
          :conditions (
                       (:use-when (type ?v tanker)   :at s1)
                       (:use-when (at-package ?p ?v) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:precond  (at-package ?p ?v) :at s2)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (hose-connected ?v ?p) :from s1 :at s5) ; :from s1
                       (:precond  (valve-open     ?v)    :from s2 :at s4)
                      )
          :variables (?p ?v ?l)
)


;;; method for loading LIVESTOCK truck or traincar with LIVESTOCK
(opschema load-vehicle-livestock      
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-down ?v))
                      (s2 :goal   (trough-full ?v))
                      (s3 :action (do-load-livestock ?p ?v))
                      (s4 :goal   (ramp-up ?v))
                     )
          :orderings ((-> s1 s2 s3 s4))
          :conditions (
                       (:use-when (type ?v livestock) :at s1)
                       (:use-when (type ?p livestock) :at s1)
                       (:use-when (at-package ?p ?l)  :at s1)
                       (:use-when (at-vehicle ?v ?l)  :at s1)
                       (:use-when (at-package ?p ?l)  :at s2)
                       (:precond  (at-package ?p ?v)  :from s3 :at s4)
                       (:use-when (at-vehicle ?v ?l)  :at s4)
                       (:precond  (ramp-down   ?v)    :from s1 :at s3)
                       (:precond  (trough-full ?v)    :from s2 :at s4)
                      )
          :variables (?p ?v ?l)
)

;;; method for unloading LIVESTOCK truck or traincar with LIVESTOCK
(opschema unload-vehicle-livestock      
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-down ?v))
                      (s2 :goal   (do-unload-livestock ?p ?v))
                      (s3 :action (do-clean-interior ?p ?v))
                      (s4 :goal   (ramp-up ?v))
                     )
          :orderings ((-> s1 s2 s3 s4))
          :conditions (
                       (:use-when (type ?v livestock) :at s1)
                       (:use-when (type ?p livestock) :at s1)
                       (:use-when (at-package ?p ?v)  :at s1)
                       (:use-when (at-vehicle ?v ?l)  :at s1)
                       (:use-when (at-package ?p ?v)  :at s2)
                       (:use-when (at-vehicle ?v ?l)  :at s4)
                       (:precond  (ramp-down   ?v)    :from s1 :at s3)
                      )
          :variables (?p ?v ?l)
)


;;; method for loading AUTO truck or traincar with CARS
(opschema load-vehicle-auto    
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-down ?v))
                      (s2 :action (do-load-cars ?p ?v))
                      (s3 :goal   (ramp-up ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v auto)  :at s1)
                       (:use-when (type ?p cars)  :at s1)
                       (:use-when (at-package ?p ?l) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?l) :at s2)
                       (:precond  (at-package ?p ?v) :from s2 :at s3)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (ramp-down  ?v) :from s1 :at s3) ; 6/05/95 bpk - was (ramp-down  ?v ?l)
                      )
          :variables (?p ?v ?l)
)

;;; method for unloading AUTO truck or traincar with CARS
(opschema unload-vehicle-auto    
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-down ?v))
                      (s2 :action (do-unload-cars ?p ?v))
                      (s3 :goal   (ramp-up ?v))
                     )
          :orderings ((-> s1 s2 s3))
          :conditions (
                       (:use-when (type ?v auto)  :at s1)
                       (:use-when (type ?p cars)  :at s1)
                       (:use-when (at-package ?p ?v) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-package ?p ?v) :at s2)
                       (:use-when (at-vehicle ?v ?l) :at s3)
                       (:precond  (ramp-down  ?v) :from s1 :at s3)  ; 6/05/95 bpk - was (ramp-down  ?v ?l)
                      )
          :variables (?p ?v ?l)
)


;;; method for loading AIRPLANE 
(opschema load-airplane       
          :todo (load ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-connected ?r ?v))
                      (s2 :goal   (door-open ?v))
                      (s3 :action (do-load-package ?p ?v))
                      (s4 :goal   (door-closed ?v))
                      (s5 :goal   (ramp-disconnected ?r))
                     )
          :orderings ((-> s1 s2 s3 s4 s5))
          
          :conditions (
                       (:use-when (type ?v airplane) :at s1)
                       (:use-when (type ?r plane-ramp) :at s1)
                       (:use-when (at-package ?p ?l) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-equipment ?r ?l) :at s1) ; ???
                       (:use-when (at-package ?p ?l) :at s3)
                       (:precond  (at-package ?p ?v) :from s3 :at s5)
                       (:use-when (at-vehicle ?v ?l) :at s5)
                       (:precond  (ramp-connected ?r ?v) :from s1 :at s5) ; 6/05/95 bpk - was (ramp-connected ?r ?p)
                       (:precond  (door-open ?v)         :from s2 :at s4)
                      )
          :variables (?p ?v ?l ?r)
)


;;; method for unloading AIRPLANE 
(opschema unload-airplane       
          :todo (unload ?p ?v ?l)
          :expansion (
                      (s1 :goal   (ramp-connected ?r ?v))
                      (s2 :goal   (door-open ?v))
                      (s3 :action (do-unload-package ?p ?v))
                      (s4 :goal   (door-closed ?v))
                      (s5 :goal   (ramp-disconnected ?r))
                     )
          :orderings ((-> s1 s2 s3 s4 s5))
          :conditions (
                       (:use-when (type ?v airplane) :at s1)
                       (:use-when (type ?r plane-ramp) :at s1)
                       (:use-when (at-package ?p ?v) :at s1)
                       (:use-when (at-vehicle ?v ?l) :at s1)
                       (:use-when (at-equipment ?r ?l) :at s1) ; ???
                       (:use-when (at-package ?p ?v) :at s3)
                       (:use-when (at-vehicle ?v ?l) :at s5)
                       (:precond  (ramp-connected ?r ?v) :from s1 :at s5) ; 6/05/95 bpk - was (ramp-connected ?r ?p)
                       (:precond  (door-open ?v)         :from s2 :at s4)
                      )
          :variables (?p ?v ?l ?r)
)

