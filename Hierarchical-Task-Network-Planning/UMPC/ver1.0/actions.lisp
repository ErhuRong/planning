(in-package "UMCP")
					;\begin{verbatim}
(operator open-door(?v)
	   :post(  
                 (door-open ?v))
)


(operator close-door(?v)
	   :post(
		 (~door-open ?v))
)

;---------------------------------------------------

(operator load-package(?p ?v ?l)
	   :pre (
		  (at-package ?p ?l)  
		  (at-vehicle ?v ?l))
	   :post(  
                  (at-package ?p ?v)
		  (~at-package ?p ?l))
)

(operator unload-package(?p ?v ?l)
	   :pre (
		 (at-package ?p ?v)  
		 (at-vehicle ?v ?l)  )
	   :post(  
		 (at-package ?p ?l)
		 (~at-package ?p ?v))
)

;---------------------------------------------------

(operator pick-up-package-ground(?p ?c ?l)
	   :pre (
		  (empty ?c)            
		  (at-equipment ?c ?l)  
		  (at-package   ?p ?l)  )
	   :post(  
                  (at-package ?p ?c)
		  (~empty ?c)
		  (~at-package ?p ?l))
)

(operator put-down-package-ground(?p ?c ?l)
	   :pre (
		  (at-equipment ?c ?l)  
		  (at-package   ?p ?c)  )
	   :post(  
                  (empty ?c)
		  (at-package ?p ?l)
		  (~at-package ?p ?c))
)


(operator pick-up-package-vehicle(?p ?c ?v ?l)
	   :pre (
			(empty ?c)
			(at-equipment ?c ?l)  
			(at-package ?p ?v)    
			(at-vehicle ?v ?l)    )
	   :post(  
		     (at-package ?p ?c)
		     (~empty ?c)
		     (~at-package ?p ?v))
)

(operator put-down-package-vehicle(?p ?c ?v ?l)
	   :pre (
			(at-package ?p ?c)    
			(at-equipment ?c ?l)  
			(at-vehicle ?v ?l)    )
	   :post(  
		     (empty ?c)
		     (at-package ?p ?v)
		     (~at-package ?p ?c))
)

;---------------------------------------------------

(operator connect-chute(?v)
	  :post(  
		    (chute-connected ?v))
)

(operator disconnect-chute(?v)
	   :post(  
		     (~chute-connected ?v))
)

;---------------------------------------------------

(operator fill-hopper(?p ?v ?l)
	   :pre (
			(chute-connected ?v)  
			(at-vehicle ?v ?l)    
			(at-package ?p ?l)    )
	   :post(  
		     (at-package ?p ?v)
		     (~at-package ?p ?l))
)

(operator empty-hopper(?p ?v ?l)
	   :pre (
			(chute-connected ?v)  
			(at-vehicle ?v ?l)    
			(at-package ?p ?v)    )
	   :post(  
		     (at-package ?p ?l)
		     (~at-package ?p ?v))
)

;---------------------------------------------------

(operator raise-ramp(?v)
	   :post(  
		 (~ramp-down ?v))
)

(operator lower-ramp(?v)
	   :post(  
		  (ramp-down ?v))
)

;---------------------------------------------------

(operator fill-trough(?v)
	   :post(  
		   (trough-full ?v))
)

;---------------------------------------------------

(operator load-livestock(?p ?v ?l)
	   :pre (
			(at-package ?p ?l)  
			(at-vehicle ?v ?l)  
			(ramp-down ?v)      )
	   :post(  
		     (at-package ?p ?v)
		     (~at-package ?p ?l)
		     (~clean-interior ?v))
)

(operator unload-livestock(?p ?v ?l)
	   :pre (
			(at-package ?p ?v)    
			(at-vehicle ?v ?l)  
			(ramp-down ?v)        )
	   :post(  
		     (at-package ?p ?l)
		     (~at-package ?p ?v)
		     (~trough-full ?v))
)

;---------------------------------------------------

(operator do-clean-interior(?v)
	   :post(  (clean-interior ?v))
)

;---------------------------------------------------

(operator load-cars(?p ?v ?l)
	:pre (
                     (at-package ?p ?l)  
                     (at-vehicle ?v ?l)  
                     (ramp-down ?v)      )
	:post(  
	          (at-package ?p ?v)
  		  (~at-package ?p ?l))
)

(operator unload-cars(?p ?v ?l)
	:pre (
		     (at-package ?p ?l)  
		     (at-vehicle ?v ?l)  
		     (ramp-down ?v)      )
	:post(  
	          (at-package ?p ?l)
		  (~at-package ?p ?v))
)

;---------------------------------------------------

(operator connect-hose(?v)
	   :post(  (hose-connected ?v))
)

(operator disconnect-hose(?v ?p)
	   :pre ( (hose-connected ?v))
	   :post( (~hose-connected ?v))
)

;---------------------------------------------------

(operator open-valve(?v)
	   :post(  (valve-open ?v)    )
)

(operator close-valve(?v)
	   :post(  (~valve-open ?v)   )
)

;---------------------------------------------------

(operator fill-tank(?v ?p ?l)
	   :pre (
			 (hose-connected ?v)  
			 (valve-open ?v)         
			 (at-package ?p ?l)      )
	   :post(  
		     (at-package ?p ?v)
		     (~at-package ?p ?l))
)

(operator empty-tank(?v ?p ?l)
	   :pre (
			(hose-connected ?v)  
			(valve-open ?v)         
			(at-package ?p ?v)      )
	   :post(  
		     (at-package ?p ?l)
		     (~at-package ?p ?v))
)

;---------------------------------------------------

(operator move-vehicle(?v ?ol ?dl ?r)
	   :pre (  (at-vehicle ?v ?ol)  )
	   :post(  
                     (at-vehicle ?v ?dl)
		     (~at-vehicle ?v ?ol))
)

;---------------------------------------------------

(operator attach-train-car(?t ?c ?l)
	   :pre (
			 (at-vehicle ?c ?l)  
			 (at-vehicle ?t ?l)  )
	   :post(  
                     (at-vehicle ?c ?t)
		     (~at-vehicle ?c ?l))
)

(operator detach-train-car(?t ?c ?l)
	   :pre (
			 (at-vehicle ?t ?l)  
			 (at-vehicle ?c ?t)  )
	   :post(  
		     (at-vehicle ?c ?l)
		     (~at-vehicle ?c ?t))
)

;---------------------------------------------------

(operator attach-conveyor-ramp(?v ?r ?l)
	   :pre (
			 (ramp-available ?r)   
			 (at-equipment ?r ?l)  
			 (at-vehicle ?v ?l)    )
	   :post(  
                     (ramp-connected ?v ?r ?l)
		     (~ramp-available ?r))
)

(operator detach-conveyor-ramp(?v ?r ?l)
	   :pre (
                         (ramp-connected ?v ?r ?l)  
			 (at-equipment ?r ?l)  
			 (at-vehicle ?v ?l)    )
	   :post(  
		     ( ramp-available ?r)
		     (~ramp-connected ?r ?v))
)

;----------------------

(operator affix-warning-signs (?v)
	   :post(  (warning-signs-affixed  ?v))
)

(operator remove-warning-signs (?v)
	   :post(  (~warning-signs-affixed  ?v))
)

;----------------------

(operator post-guard-outside(?v)
	   :post(  (guard-outside ?v)
		   (~guard-inside ?v))
)

(operator post-guard-inside(?v)
	   :post(  (guard-inside ?v)
		   (~guard-outside ?v))
)

(operator remove-guard(?v)
	   :post(    (~guard-outside ?v)
		     (~guard-inside ?v))
)

;----------------------

(operator decontaminate-interior(?v)
	   :post(  (decontaminated-interior ?v))
)


(operator obtain-permit(?p)
	   :post(  (have-permit ?p))
)

(operator collect-fees(?p)
	   :post(  (fees-collected ?p))
)

(operator collect-insurance(?p)
	   :post(  (insured ?p))
)

(operator deliver(?p)
	   :post(    (~have-permit ?p)
		     (~fees-collected ?p)
		     (~insured ?p))
)



;\end{verbatim}