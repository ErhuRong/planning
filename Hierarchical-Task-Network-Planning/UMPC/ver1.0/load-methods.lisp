(in-package "UMCP")
;\begin{verbatim}
(variables ?p ?v ?l ?c ?r)

(declare-method load-top (?p ?v ?l)
	   :expansion(
		      (n1 load-haz ?p ?v ?l)
		      (n2 load-val ?p ?v ?l)
		      )
	   :formula (ord n1 n2)
)

(declare-method unload-top (?p ?v ?l)
	   :expansion(
		      (n1 unload-haz ?p ?v ?l)
		      (n2 unload-val ?p ?v ?l)
		      )
	   :formula (ord n2 n1)
)

(declare-method load-haz (?p ?v ?l)
	   :expansion( 
		      (n warning-signs-affixed ?p ?v)
		      )
	   :formula (initially (type ?p hazardous))
)

(declare-method load-haz (?p ?v ?l)
	   :expansion( 
		      (n do-nothing)
		      )
	   :formula (initially (~type ?p hazardous))
)
(declare-method unload-haz (?p ?v ?l)
	   :expansion( 
		      (n1 decontaminated-interior ?v)
		      (n2 ~warning-signs-affixed  ?v)
		      )
	   :formula (and
		     (initially (type ?p hazardous))
		     (ord n1 n2))
)

(declare-method unload-haz (?p ?v ?l)
	   :expansion( 
		      (n do-nothing)
		      )
	   :formula (initially (~type ?p hazardous))
)

(declare-method load-val (?p ?v ?l)
	   :expansion( 
		      (n load ?p ?v ?l)
		      )
	   :formula (initially (~type ?p valuable))
)

(declare-method unload-val (?p ?v ?l)
	   :expansion( 
		      (n unload ?p ?v ?l)
		      )
	   :formula (initially (~type ?p valuable))
)


(declare-method load-val (?p ?v ?l)
	   :expansion( 
		      (n1 guard-outside ?v)
		      (n2 load ?p ?v ?l)
		      (n3 guard-inside ?v)
		      )
	   :formula (and 
		     (ord n1 n2)
		     (ord n2 n3)
		     (initially (type ?p valuable))
		     )
)

(declare-method unload-val (?p ?v ?l)
	   :expansion( 
		      (n1 guard-outside ?v)
		      (n2 unload ?p ?v ?l)
		      )
	   :formula (and 
		     (ord n1 n2)
		     (initially (type ?p valuable)))
)



;;; 
;;; declare-method for loading REGULAR truck or traincar
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1  door-open ?v)
                      (n2  load-package ?p ?v ?l)
                      (n3  ~door-open ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v regular)  )
                       (between (at-package ?p ?l)  n1 n2)
                       (between  (at-package ?p ?v)  n2  n3)
                       (between (at-vehicle ?v ?l)  n1 n3)
                       (between  (door-open  ?v)     n1  n3) 
                      )
)

;;; declare-method for unloading REGULAR truck or traincar
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1    door-open ?v)
                      (n2    unload-package ?p ?v ?l)
                      (n3    ~door-open ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v regular)  )
                       (before (at-package ?p ?v)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-vehicle ?v ?l)  n3)
                       (before (at-package ?p ?v)  n2)
                       (between  (door-open  ?v)     n1  n3)
                      )
)

;;; ---------------------------
;;; declare-method for loading FLATBED truck or traincar
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1  pick-up-package-ground   ?p ?c ?l)
                      (n2  put-down-package-vehicle ?p ?c ?v ?l)
                     )
          :formula (and
                       (ord n1 n2)
                       (initially (type ?v flatbed)     )
                       (initially (type ?c crane)       )
                       (before (empty ?c)            n1) 
                       (before (at-package   ?p ?l)  n1)
                       (before (at-equipment ?c ?l)  n1)
                       (between  (at-package   ?p ?c)  n1  n2)
                       (before (at-vehicle   ?v ?l)  n2)
                       (between (at-equipment ?c ?l)  n1 n2) 
                      )
)

;;; declare-method for unloading FLATBED truck or traincar
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1  pick-up-package-vehicle  ?p ?c ?v ?l)
                      (n2  put-down-package-ground ?p ?c ?l)
                     )
          :formula (and
                       (ord n1 n2)
                       (initially (type ?v flatbed)     )                     
                       (before (at-package   ?p ?v)  n1)
                       (before (at-vehicle   ?v ?l)  n1)
                       (before (at-equipment ?c ?l)  n1)
                       (initially (type ?c crane)       )
                       (before (empty ?c)            n1) 
                       (between  (at-package   ?p ?c)  n1  n2)
                       (between (at-equipment ?c ?l)  n1 n2) 
                      )
)

;;; declare-method for loading HOPPER truck or traincar
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1    chute-connected ?v)
                      (n2    fill-hopper ?p ?v ?l)
                      (n3    ~chute-connected ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v hopper)   )
                       (before (at-package ?p ?l)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-package ?p ?l)  n2)
                       (between  (at-package ?p ?v)  n2  n3)
                       (before (at-vehicle ?v ?l)    n3)
                       (between  (chute-connected ?v)  n1  n3)
                      )
)

;;; declare-method for unloading HOPPER truck or traincar
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1  chute-connected ?v)
                      (n2  empty-hopper ?p ?v ?l)
                      (n3  ~chute-connected ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v hopper)    n1)
                       (before (at-package ?p ?v)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-package ?p ?v)  n2)
                       (before (at-vehicle ?v ?l)  n3)
                       (between  (chute-connected ?v)  n1  n3)
                      )
) 


;;; declare-method for loading TANKER truck or traincar
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1    hose-connected ?v )
                      (n2    valve-open ?v)
                      (n3    fill-tank ?v ?p ?l)
                      (n4    ~valve-open ?v)
                      (n5    ~hose-connected ?v )
                     )
            :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
		       (ord n4 n5)
                       (initially (type ?v tanker)   )
                       (before (at-package ?p ?l)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-package ?p ?l)  n2)
                       (between  (at-package ?p ?v)  n3  n4)
                       (before (at-vehicle ?v ?l)  n3)
                       (between  (hose-connected ?v )  n1  n5)
                       (between  (valve-open     ?v)     n2  n4)
                      )
)

;;; declare-method for unloading TANKER truck or traincar
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1    hose-connected ?v )
                      (n2    valve-open ?v)
                      (n3    empty-tank ?v ?p ?l)
                      (n4    ~valve-open ?v)
                      (n5    ~hose-connected ?v )
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
		       (ord n4 n5)
                       (initially (type ?v tanker)    )
                       (before (at-package ?p ?v)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (between  (at-package ?p ?v)  n2 n3)
                       (between (at-vehicle ?v ?l)  n1 n5)
                       (between  (hose-connected ?v )  n1  n5)
                       (between  (valve-open     ?v)     n2  n4)
                      )
)


;;; declare-method for loading LIVESTOCK 
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1    ramp-down ?v)
                      (n2    trough-full ?v)
                      (n3    load-livestock ?p ?v ?l)
                      (n4    ~ramp-down ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
                       (initially (type ?v livestock)  )
                       (initially (type ?p livestock)  )
                       (before (at-package ?p ?l)   n1)
                       (before (at-vehicle ?v ?l)   n1)
                       (before (at-package ?p ?l)   n2)
                       (between  (at-package ?p ?v)   n3  n4)
                       (before (at-vehicle ?v ?l)   n4)
                       (between  (ramp-down   ?v)     n1  n3)
                       (between  (trough-full ?v)     n2  n4)
                      )
)

;;; declare-method for unloading LIVESTOCK 
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1    ramp-down ?v)
                      (n2    unload-livestock ?p ?v ?l)
                      (n3    clean-interior  ?v)
                      (n4    ~ramp-down ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
                       (initially (type ?v livestock)  )
                       (initially (type ?p livestock)  )
                       (before (at-package ?p ?v)   n1)
                       (before (at-vehicle ?v ?l)   n1)
                       (before (at-package ?p ?v)   n2)
                       (before (at-vehicle ?v ?l)   n4)
                       (between  (ramp-down   ?v)     n1  n3)
                      )
)


;;; declare-method for loading AUTO truck or traincar with CARS
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1    ramp-down ?v)
                      (n2    load-cars ?p ?v ?l)
                      (n3    ~ramp-down ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v auto)   )
                       (initially (type ?p cars)   )
                       (before (at-package ?p ?l)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-package ?p ?l)  n2)
                       (between  (at-package ?p ?v)  n2  n3)
                       (before (at-vehicle ?v ?l)  n3)
                       (between  (ramp-down  ?v)  n1  n3)
                      )
)

;;; declare-method for unloading AUTO truck or traincar with CARS
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1    ramp-down ?v)
                      (n2    unload-cars ?p ?v ?l)
                      (n3    ~ramp-down ?v)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
                       (initially (type ?v auto)   )
                       (initially (type ?p cars)   )
                       (before (at-package ?p ?v)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-package ?p ?v)  n2)
                       (before (at-vehicle ?v ?l)  n3)
                       (between  (ramp-down  ?v )  n1  n3)
                      )
)


;;; declare-method for loading AIRPLANE 
(declare-method load (?p ?v ?l)
          :expansion (
                      (n1    ramp-connected ?v ?r ?l)
                      (n2    door-open ?v)
                      (n3    load-package ?p ?v ?l)
                      (n4    ~door-open ?v)
                      (n5    ~ramp-connected ?v ?r ?l)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
		       (ord n4 n5)
                       (initially (type ?v airplane)  )
                       (initially (type ?r plane-ramp)  )
                       (before (ramp-available ?r)   n1)
                       (before (at-package ?p ?l)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-equipment ?r ?l)  n1)
                       (before (at-package ?p ?l)  n3)
                       (between  (at-package ?p ?v)  n3  n5)
                       (before (at-vehicle ?v ?l)  n5)
                       (between  (ramp-connected ?v ?r ?l)  n1  n5)
                       (between  (door-open ?v)          n2  n4)
                      )
)


;;; declare-method for unloading AIRPLANE 
(declare-method unload (?p ?v ?l)
          :expansion (
                      (n1    ramp-connected ?v ?r ?l)
                      (n2    door-open ?v)
                      (n3    unload-package ?p ?v ?l)
                      (n4    ~door-open ?v)
                      (n5    ~ramp-connected ?v ?r ?l)
                     )
          :formula (and
                       (ord n1 n2)
		       (ord n2 n3)
	               (ord n3 n4)
		       (ord n4 n5)
                       (initially (type ?v airplane)  )
                       (initially (type ?r plane-ramp)  )
                       (before (ramp-available ?r)   n1)
                       (before (at-package ?p ?v)  n1)
                       (before (at-vehicle ?v ?l)  n1)
                       (before (at-equipment ?r ?l)  n1) 
                       (before (at-package ?p ?v)  n3)
                       (before (at-vehicle ?v ?l)  n5)
                       (between  (ramp-connected ?v ?r ?l)  n1  n5)
                       (between  (door-open ?v)          n2  n4)
                      )
)

;\end{verbatim}