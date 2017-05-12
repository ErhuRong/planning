;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;;    Application:  Nonlin/Priar
;;;;  Appl. Version:  1.3
;;;;     Appl. Date:  Oct.1992
;;;;
;;;;           File:  UMT-ACTIONS-NL.LISP
;;;;       Contents:  Nonlin schema defns for Actions in the UM-Translog domain.
;;;;
;;;;         Author:  
;;;;
;;;;                  Dept. of Computer Science, University of Maryland at College Park
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
;;;;   6/05/95       changed package specifier and commented out lines,
;;;;                 fixed typo in EMPTY-HOPPER, error in REMOVE-WARNING-SIGNS
;;;;   7/18/94       replaced :use-only-for-query conditions with :use-when conditions
;;;;   6/21/94       created

(setq autocond nil)

(actschema open-door
	   :todo (door-open ?v)
	   :expansion ((s1 :primitive (p-open-door ?v)))
	   :effects   ((s1 :assert    (door-open ?v))
		       (s1 :delete    (door-closed ?v)))
	   :variables (?v)
)


(actschema close-door
	   :todo (door-closed ?v)
	   :expansion ((s1  :primitive (p-close-door ?v)))
	   :effects   ((s1  :assert    (door-closed ?v))
		       (s1  :delete    (door-open ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema load-package
	   :todo (do-load-package ?p ?v)
	   :expansion ((s1  :primitive (p-load-package ?p ?v)))
	   :conditions (
			(:use-when (at-package ?p ?l) :at s1)
		        (:use-when (at-vehicle ?v ?l) :at s1))
	   :effects ((s1 :assert (at-package ?p ?v))
		     (s1 :delete (at-package ?p ?l)))
	   :variables (?p ?v ?l)
)

(actschema unload-package
	   :todo (do-unload-package ?p ?v)
	   :expansion ((s1  :primitive (p-unload-package ?p ?v)))
	   :conditions (
			(:use-when (at-package ?p ?v) :at s1)
			(:use-when (at-vehicle ?v ?l) :at s1))
	   :effects ((s1 :assert (at-package ?p ?l))
		     (s1 :delete (at-package ?p ?v)))
	   :variables (?p ?v ?l)
)

;---------------------------------------------------------------------------

(actschema pick-up-package-ground
	   :todo (do-pick-up-package-ground ?p ?c)
	   :expansion ((s1 :primitive (p-pick-up-package-ground ?p ?c)))
	   :conditions (
			(:use-when (empty ?c)           :at s1)
			(:use-when (at-equipment ?c ?l) :at s1)
			(:use-when (at-package   ?p ?l) :at s1))
	   :effects ((s1 :assert (at-package ?p ?c))
		     (s1 :delete (empty ?c))
		     (s1 :delete (at-package ?p ?l)))
	   :variables (?p ?c ?l)
)

(actschema put-down-package-ground
	   :todo (do-put-down-package-ground ?p ?c)
	   :expansion ((s1 :primitive (p-put-down-package-ground ?p ?c)))
	   :conditions (
			(:use-when (at-equipment ?c ?l) :at s1)
			(:use-when (at-package   ?p ?c) :at s1))
	   :effects ((s1 :assert (empty ?c))
		     (s1 :assert (at-package ?p ?l))
		     (s1 :delete (at-package ?p ?c)))
	   :variables (?p ?c ?l)
)

;---------------------------------------------------------------------------

(actschema pick-up-package-vehicle
	   :todo (do-pick-up-package-vehicle ?p ?c ?v)
	   :expansion ((s1 :primitive (p-pick-up-package-vehicle ?p ?c ?v)))
	   :conditions (
			(:use-when (empty ?c))
			(:use-when (at-equipment ?c ?l) :at s1)
			(:use-when (at-package ?p ?v)   :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1))
	   :effects ((s1 :assert (at-package ?p ?c))
		     (s1 :delete (empty ?c))
		     (s1 :delete (at-package ?p ?v)))
	   :variables (?p ?c ?v ?l)
)

(actschema put-down-package-vehicle
	   :todo (do-put-down-package-vehicle ?p ?c ?v)
	   :expansion ((s1 :primitive (p-put-down-package-vehicle ?p ?c ?v)))
	   :conditions (
			(:use-when (at-package ?p ?c)   :at s1)
			(:use-when (at-equipment ?c ?l) :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1))
	   :effects ((s1 :assert (empty ?c))
		     (s1 :assert (at-package ?p ?v))
		     (s1 :delete (at-package ?p ?c)))
	   :variables (?p ?c ?v ?l)
)

;---------------------------------------------------------------------------

(actschema connect-chute
	  :todo (chute-connected ?v)
	  :expansion ((s1 :primitive (p-connect-chute ?v)))
	  :effects ((s1 :assert (chute-connected ?v))
		    (s1 :delete (chute-disconnected ?v)))
	  :variables (?v)
)

(actschema disconnect-chute
	   :todo (chute-disconnected ?v)
	   :expansion ((s1 :primitive (p-disconnect-chute ?v)))
	   :effects ((s1 :assert (chute-disconnected ?v))
		     (s1 :delete (chute-connected ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema fill-hopper
	   :todo (do-fill-hopper ?p ?v)
	   :expansion ((s1 :primitive (p-fill-hopper ?p ?v)))
	   :conditions (
			(:use-when (chute-connected ?v) :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1)
			(:use-when (at-package ?p ?l)   :at s1))
	   :effects ((s1 :assert (at-package ?p ?v))
		     (s1 :delete (at-package ?p ?l)))
	   :variables (?p ?v ?l)
)

(actschema empty-hopper
	   :todo (do-empty-hopper ?p ?v)
	   :expansion ((s1 :primitive (p-empty-hopper ?p ?v)))
	   :conditions (
			(:use-when (chute-connected ?v) :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1)
			(:use-when (at-package ?p ?v)   :at s1))
	   :effects ((s1 :assert (at-package ?p ?l)) ; 6/05/95 bpk - fixed typo "pakcage"
		     (s1 :delete (at-package ?p ?v)))
	   :variables (?p ?v ?l)
)

;---------------------------------------------------------------------------

(actschema raise-ramp
	   :todo (ramp-up ?v)
	   :expansion ((s1 :primitive (p-raise-ramp ?v)))
	   :effects ((s1 :assert (ramp-up ?v))
		     (s1 :delete (ramp-down ?v)))
	   :variables (?v)
)

(actschema lower-ramp
	   :todo (ramp-down ?v)
	   :expansion ((s1 :primitive (p-lower-ramp ?v)))
	   :effects ((s1 :assert (ramp-down ?v))
		     (s1 :delete (ramp-up ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema fill-trough
	   :todo (trough-full ?v)
	   :expansion ((s1 :primitive (p-fill-trough ?v)))
	   :effects ((s1 :assert (trough-full ?v))
		     (s1 :delete (trough-empty ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema load-livestock
	   :todo (do-load-livestock ?p ?v)
	   :expansion ((s1 :primitive (p-load-livestock ?p ?v)))
	   :conditions (
			(:use-when (at-package ?p ?l) :at s1)
			(:use-when (at-vehicle ?v ?l) :at s1)
			(:use-when (ramp-down ?v)     :at s1))
	   :effects ((s1 :assert (at-package ?p ?v))
		     (s1 :assert (dirty-interior ?v))
		     (s1 :delete (at-package ?p ?l))
		     (s1 :delete (clean-interior ?v)))
	   :variables (?p ?v ?l)
)

(actschema unload-livestock
	   :todo (do-unload-livestock ?p ?v)
	   :expansion ((s1 :primitive (p-unload-livestock ?p ?v)))
	   :conditions (
			(:use-when (at-package ?p ?v)   :at s1)
			(:use-when (at-vehicle ?v ?l) :at s1)
			(:use-when (ramp-down ?v)       :at s1))
	   :effects ((s1 :assert (at-package ?p ?l))
		     (s1 :assert (trough-empty ?v))
		     (s1 :delete (at-package ?p ?v))
		     (s1 :delete (trough-full ?v)))
	   :variables (?p ?v ?l)
)

;---------------------------------------------------------------------------

(actschema clean-interior
	   :todo (clean-interior ?v)
	   :expansion ((s1 :primitive (p-clean-interior ?v)))
	   :effects ((s1 :assert (clean-interior ?v))
		     (s2 :delete (dirty-interior ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema load-cars
	:todo (do-load-cars ?p ?v)
	:expansion ((s1 :primitive (p-load-cars ?p ?v)))
	:conditions (
                     (:use-when (at-package ?p ?l) :at s1)
                     (:use-when (at-vehicle ?v ?l) :at s1)
                     (:use-when (ramp-down ?v)     :at s1))
	:effects ((s1 :assert (at-package ?p ?v))
  		  (s1 :delete (at-package ?p ?l)))
	:variables (?p ?v ?l)
)

(actschema unload-cars
	:todo (do-unload-cars ?p ?v)
	:expansion ((s1 :primitive (p-unload-cars ?p ?v)))
	:conditions (
		     (:use-when (at-package ?p ?v) :at s1)
		     (:use-when (at-vehicle ?v ?l) :at s1)
		     (:use-when (ramp-down ?v)     :at s1))
	:effects ((s1 :assert (at-package ?p ?l))
		  (s1 :delete (at-package ?p ?v)))
	:variables (?p ?v ?l)
)

;---------------------------------------------------------------------------

(actschema connect-hose
	   :todo (hose-connected ?v ?p)
	   :expansion ((s1 :primitive (p-connect-hose ?v ?p)))
	   :effects ((s1 :assert (hose-connected ?v ?p))
		     (s1 :delete (hose-disconnected ?v)))
	   :variables (?v ?p ?l)
)

(actschema disconnect-hose
	   :todo (hose-disconnected ?v)
	   :expansion ((s1 :primitive (p-disconnect-hose ?v)))
	   :conditions ((:use-when (hose-connected ?v ?p)))
	   :effects ((s1 :assert (hose-disconnected ?v))
		     (s1 :delete (hose-connected ?v ?p)))
	   :variables (?v ?p)
)

;---------------------------------------------------------------------------

(actschema open-valve
	   :todo (valve-open ?v)
	   :expansion ((s1 :primitive (p-open-vehicle-valve ?v)))
	   :effects ((s1 :assert (valve-open ?v)   :at s1)
		     (s1 :delete (valve-closed ?v) :at s1))
	   :variables (?v)
)

(actschema close-valve
	   :todo (valve-closed ?v)
	   :expansion ((s1 :primitive (p-close-vehicle-valve ?v)))
	   :effects ((s1 :assert (valve-closed ?v) :at s1)
		     (s1 :delete (valve-open ?v)   :at s1))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema fill-tank
	   :todo (do-fill-tank ?v ?p)
	   :expansion ((s1 :primitive (p-fill-tank ?v ?p)))
	   :conditions (
			(:use-when (hose-connected ?v ?p) :at s1)
			(:use-when (valve-open ?v)        :at s1)
			(:use-when (at-package ?p ?l)     :at s1))
	   :effects ((s1 :assert (at-package ?p ?v))
		     (s1 :delete (at-package ?p ?l)))
	   :variables (?v ?p ?l)
)

(actschema empty-tank
	   :todo (do-empty-tank ?v ?p)
	   :expansion ((s1 :primitive (p-empty-tank ?v ?p)))
	   :conditions (
			(:use-when (hose-connected ?v ?p) :at s1)
			(:use-when (valve-open ?v)        :at s1)
			(:use-when (at-package ?p ?v)     :at s1))
	   :effects ((s1 :assert (at-package ?p ?l))
		     (s1 :delete (at-package ?p ?v)))
	   :variables (?v ?p ?l)
)

;---------------------------------------------------------------------------

(actschema move-vehicle
	   :todo (do-move-vehicle ?v ?ol ?dl ?r)
	   :expansion ((s1 :primitive (p-move-vehicle ?v ?ol ?dl ?r)))
	   :conditions ((:use-when (at-vehicle ?v ?ol) :at s1))
	   :effects ((s1 :assert (at-vehicle ?v ?dl))
		     (s1 :delete (at-vehicle ?v ?ol)))
	   :variables (?v ?ol ?dl ?r)
)

;---------------------------------------------------------------------------

(actschema attach-train-car
	   :todo (do-attach-traincar ?t ?c)
	   :expansion ((s1 :primitive (p-attach-traincar ?t ?c)))
	   :conditions (
			(:use-when (at-vehicle ?c ?l) :at s1)
			(:use-when (at-vehicle ?t ?l) :at s1))
	   :effects ((s1 :assert (at-vehicle ?c ?t))
		     (s1 :delete (at-vehicle ?c ?l)))
	   :variables (?t ?c ?l)
)

(actschema detach-train-car
	   :todo (do-detach-traincar ?t ?c)
	   :expansion ((s1 :primitive (p-detach-traincar ?t ?c)))
	   :conditions (
			(:use-when (at-vehicle ?t ?l) :at s1)
			(:use-when (at-vehicle ?c ?t) :at s1))
	   :effects ((s1 :assert (at-vehicle ?c ?l))
		     (s1 :delete (at-vehicle ?c ?t)))
	   :variables (?t ?c ?l)
)

;---------------------------------------------------------------------------

(actschema attach-conveyor-ramp
	   :todo (ramp-connected ?r ?v)
	   :expansion ((s1 :primitive (p-attach-conveyor-ramp ?r ?v)))
	   :conditions (
			(:use-when (ramp-disconnected ?r)  :at s1)
			(:use-when (at-equipment ?r ?l) :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1))
	   :effects ((s1 :assert (ramp-connected ?r ?v))
		     (s1 :delete (ramp-disconnected ?r)))
	   :variables (?v ?r ?l)
)

(actschema detach-conveyor-ramp
	   :todo (ramp-disconnected ?r)
	   :expansion ((s1 :primitive (p-detach-conveyor-ramp ?r ?v)))
	   :conditions (
                        (:use-when (ramp-connected ?r ?v) :at s1)
			(:use-when (at-equipment ?r ?l) :at s1)
			(:use-when (at-vehicle ?v ?l)   :at s1))
	   :effects ((s1 :assert (ramp-disconnected ?r))
		     (s1 :delete (ramp-connected ?r ?v)))
	   :variables (?v ?r ?l)
)

;---------------------------------------------------------------------------

(actschema affix-warning-signs 
	   :todo (warning-signs-affixed ?p ?v)
	   :expansion ((s1 :primitive (p-affix-warning-signs ?p ?v)))
	   :effects ((s1 :assert (warning-signs-affixed ?p ?v)))
	   :variables (?p ?v)
)

(actschema remove-warning-signs 
	   :todo (warning-signs-removed ?p ?v)
	   :expansion  ((s1 :primitive (p-remove-warning-signs ?p ?v)))
           :conditions ((:use-when (warning-signs-affixed ?p ?v) :at s1)) ; added 6/05/95
	   :effects ((s1 :assert (warning-signs-removed ?p ?v))
                     (s1 :delete (warning-signs-affixed ?p ?v))) ; was (warning-signs-affixed)
	   :variables (?p ?v) ; was (?v)
)

;---------------------------------------------------------------------------

(actschema post-guard-outside
	   :todo (guard-outside ?v)
	   :expansion ((s1 :primitive (p-post-guard-outside ?v)))
	   :effects ((s1 :assert (guard-outside ?v))
		     (s1 :delete (guard-inside ?v)))
	   :variables (?v)
)

(actschema post-guard-inside
	   :todo (guard-inside ?v)
	   :expansion ((s1 :primitive (p-post-guard-inside ?v)))
	   :effects ((s1 :assert (guard-inside ?v))
		     (s1 :delete (guard-outside ?v)))
	   :variables (?v)
)

(actschema remove-guard
	   :todo (guard-removed ?v)
	   :expansion ((s1 :primitive (p-remove-guard ?v)))
	   :effects ((s1 :delete (guard-outside ?v))
		     (s1 :delete (guard-inside ?v)))
	   :variables (?v)
)

;---------------------------------------------------------------------------

(actschema decontaminate-interior
	   :todo (decontaminated-interior ?v)
	   :expansion ((s1 :primitive (p-decontaminate ?v)))
	   :effects ((s1 :assert (decontaminated-interior ?v)))
	   :variables (?v)
)


(actschema obtain-permit
	   :todo (have-permit ?p)
	   :expansion ((s1 :primitive (p-obtain-permit ?p)))
	   :effects ((s1 :assert (have-permit ?p)))
	   :variables (?p)
)

(actschema collect-fees
	   :todo (fees-collected ?p)
	   :expansion ((s1 :primitive (p-collect-fees ?p)))
	   :effects ((s1 :assert (fees-collected ?p)))
	   :variables (?p)
)

(actschema collect-insurance
	   :todo (insured ?p)
	   :expansion ((s1 :primitive (p-collect-insurance ?p)))
	   :effects ((s1 :assert (insured ?p)))
	   :variables (?p)
)

(actschema deliver
	   :todo (do-deliver ?p)
	   :expansion ((s1 :primitive (p-deliver ?p)))
	   :effects ((s1 :delete (have-permit ?p))
		     (s1 :delete (fees-collected ?p))
		     (s1 :delete (insured ?p)))
	   :variables (?p)
)



							 
                                                         
