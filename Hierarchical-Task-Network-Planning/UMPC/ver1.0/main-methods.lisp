(in-package "UMCP")
					;\begin{verbatim}
(variables ?package 
	   ?origin ?destination  ?location 
	   ?ocity ?dcity ?city1 ?city2 ?samecity
	   ?tcenter ?tcenter1 ?tcenter2 ?tt  
	   ?region1 ?region2 ?hub  
	   ?vehicle  ?tc ?train
	   ?ptype ?vtype ?route ?r ?rtype ?vptype ?type1
	    
)


;;; top-level declare-method: used for top-level goal
(declare-method AT-PACKAGE(?package ?destination)
   :expansion (
               (n1 TRANSPORT ?package ?origin ?destination)
              )
   :formula (and
	       (initially (AT-PACKAGE ?package ?origin) )
               (after  (AT-PACKAGE ?package ?destination) n1))
)


(declare-method TRANSPORT(?package ?origin ?destination)
          :expansion (
		      (n1  PICKUP  ?package)
 		      (n2  CARRY   ?package ?origin ?destination)
 		      (n3  DELIVER ?package)
                     )
          :formula (and (ord n1 n2) (ord n2 n3))
;         :effects (
 ;                   (n2 :delete (AT-PACKAGE ?package ?origin))
  ;                  (n2 :assert (AT-PACKAGE ?package ?destination))
   ;                 )
 )
;------------------------------
; PICKUP DECLARE-METHODS
;------------------------------

(declare-method PICKUP(?package)  
          :expansion (
                     (n1  COLLECT-FEES     ?package)
                     (n2  HANDLE-INSURANCE ?package)
                     (n3  HANDLE-HAZARDOUS ?package))
)

;------------------------------

(declare-method HANDLE-INSURANCE(?package)  
          :expansion (
                      (n1  COLLECT-INSURANCE ?package)
                     )
          :formula (initially (TYPE ?package VALUABLE))
)

(declare-method HANDLE-INSURANCE(?package)  
          :expansion (
                      (n1 DO-NOTHING)
                     )
          :formula (initially (~TYPE ?package VALUABLE))
)

;--------------------------

(declare-method HANDLE-HAZARDOUS(?package)  
          :expansion (
                      (n1  OBTAIN-PERMIT ?package)
                     )
          :formula (initially (TYPE ?package HAZARDOUS) n1)
)

(declare-method HANDLE-HAZARDOUS(?package)  
          :expansion (
                      (n1 DO-NOTHING)
                     )
          :formula (initially (~TYPE ?package HAZARDOUS) )
)
					

;--------------------------
;  CARRY DECLARE-METHODS - TOP LEVEL.  ** THESE BIND TCENTERS **
;--------------------------

;;; top-level carry declare-method 1
(declare-method CARRY(?package ?origin ?destination)  
          :expansion (
                      (n1 CARRY-DIRECT ?package ?origin ?destination)
                     )
;         :effects (
 ;                   (n1 :delete (AT-PACKAGE ?package ?origin))
  ;                  (n1 :assert (AT-PACKAGE ?package ?destination))
   ;                 )
)

;;; 2 carry: 
;;;?origin (tcenter, not hub) -> ?destination (tcenter, not hub)	
(declare-method CARRY(?package  ?origin  ?destination)  
          :expansion(
                     (n1  CARRY-VIA-HUB ?package ?origin ?destination)
                     ) 
;         :effects (
 ;                   (n1 :delete (AT-PACKAGE ?package ?origin))
  ;                  (n1 :assert (AT-PACKAGE ?package ?destination))
   ;                 )
  
          :formula (and
                       (initially (IN-CITY ?origin      ?ocity))
                       (initially (IN-CITY ?destination ?dcity))
                       (not (veq ?ocity ?dcity)) 
                       (initially (TYPE ?origin      TCENTER))
                       (initially (TYPE ?destination TCENTER))
                       (initially (~TYPE ?origin   HUB  ))
                       (initially (~TYPE ?destination HUB))
                       (initially (AVAILABLE ?origin))
                       (initially (AVAILABLE ?destination))
                      )
)

;;; 3 carry: 
;;;?origin (not tcenter) -> ?tcenter -> ?destination (tcenter)
(declare-method CARRY(?package ?origin ?destination)  
          :expansion (
		      (n0  CARRY-DIRECT ?package ?origin ?tcenter)
                      (n1  CARRY-BETWEEN-TCENTERS 
			   ?package ?tcenter ?destination)
                     )     
;          :effects (
 ;                   (s0 :delete (AT-PACKAGE ?package ?origin))
  ;                  (s0 :assert (AT-PACKAGE ?package ?tcenter))
   ;                 (n1 :delete (AT-PACKAGE ?package ?tcenter))
    ;                (n1 :assert (AT-PACKAGE ?package ?destination))
     ;               )
          :formula (and
	               (ord n0 n1)
                       (initially (~TYPE ?origin      TCENTER) )
                       (initially (TYPE ?destination TCENTER)  )
                       (initially (IN-CITY ?origin ?ocity)     )
                       (initially (IN-CITY ?destination ?dcity))
                       (not (veq ?ocity ?dcity))
                       (initially (SERVES ?tcenter ?ocity) ) 
                       (initially (TYPE ?tcenter TCENTER) )
	               (not (veq ?tcenter ?destination) )
                       (initially (TYPE ?tcenter ?tt) )
                       (not (veq ?tt TCENTER))
                       (initially (TYPE ?destination ?tt))
                       (initially (AVAILABLE ?tcenter)  )
                       (initially (AVAILABLE ?destination))                      
                      )
)

;;; 4 carry: 
;;; ?origin (tcenter) -> ?tcenter -> ?destination (not tcenter)
(declare-method CARRY(?package ?origin ?destination)  
          :expansion (
		      (n1  CARRY-BETWEEN-TCENTERS ?package  ?origin ?tcenter)
		      (n2  CARRY-DIRECT ?package  ?tcenter ?destination)
                     ) 
;          :effects (
 ;                   (n1 :delete (AT-PACKAGE ?package ?origin))
  ;                  (n1 :assert (AT-PACKAGE ?package ?tcenter))
   ;                 (n2 :delete (AT-PACKAGE ?package ?tcenter))
    ;                (n2 :assert (AT-PACKAGE ?package ?destination))
     ;               )
          :formula (and 
                       (ord n1 n2)
                       (initially (TYPE ?origin      TCENTER)      )
                       (initially (~TYPE ?destination TCENTER)  )
                       (initially (IN-CITY ?origin ?ocity)       )
                       (initially (IN-CITY ?destination ?dcity)  )
                       (not (veq ?ocity ?dcity))
                       (initially (SERVES ?tcenter ?dcity)  ) 
	               (initially (TYPE ?tcenter TCENTER)  )
                       (initially (TYPE ?tcenter ?tt)  )
                       (not (veq ?tt TCENTER))
                       (initially (TYPE ?origin ?tt)  )
                       (not (veq ?tcenter ?origin))
                       (initially (AVAILABLE ?origin)       )
                       (initially (AVAILABLE ?tcenter)      )
                      )
)

;;; carry: 
;; ?origin (not tcenter) -> 
;;       ?tcenter1 -> ?tcenter2 -> ?destination (not tcenter)
(declare-method CARRY(?package  ?origin  ?destination)  
          :expansion (
                      (n0  CARRY-DIRECT ?package  ?origin   ?tcenter1)
                      (n1  CARRY-BETWEEN-TCENTERS 
                           ?package  ?tcenter1 ?tcenter2)
                      (n2  CARRY-DIRECT 
                           ?package  ?tcenter2 ?destination)
                     )
;          :effects (
 ;                   (n1 :delete (AT-PACKAGE ?package ?tcenter1))
  ;                  (n1 :assert (AT-PACKAGE ?package ?tcenter2))
   ;                 (n0 :delete (AT-PACKAGE ?package ?origin))
    ;                (n0 :assert (AT-PACKAGE ?package ?tcenter1))
     ;               (n2 :assert (AT-PACKAGE ?package ?destination))
      ;              (n2 :delete (AT-PACKAGE ?package ?tcenter2)))
          :formula (and
                       (ord n0 n1)
	               (ord n1 n2)
                       (initially (~TYPE ?origin      TCENTER)  )
                       (initially (~TYPE ?destination TCENTER)  )
                       (initially (IN-CITY ?origin ?ocity)       )
                       (initially (IN-CITY ?destination ?dcity)  )
                       (not (veq ?ocity ?dcity))
                       (initially (SERVES ?tcenter1 ?ocity)  ) 
                       (initially (SERVES ?tcenter2 ?dcity)  ) 
	               (initially (TYPE ?tcenter1 TCENTER)  )
                       (initially (TYPE ?tcenter1 ?tt)      )
                       (not (veq ?tt TCENTER))
                       (initially (TYPE ?tcenter2 ?tt)  )
	               (initially (TYPE ?tcenter2 TCENTER)  )
                       (initially (AVAILABLE ?tcenter1)  )
                       (initially (AVAILABLE ?tcenter2)  )                      
                      )
)
					
;--------------------------
;  CARRY DECLARE-METHODS - BETWEEN TCENTERS. 
;--------------------------

;;; carry: ?tcenter1 -> ?tcenter2 where ?tcenter1 = ?tcenter2
(declare-method CARRY-BETWEEN-TCENTERS(?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (n1 DO-NOTHING))
;          :effects (
 ;                   (n1 :delete (AT-PACKAGE ?package ?tcenter1))
  ;                  (n1 :assert (AT-PACKAGE ?package ?tcenter2)))
          :formula (veq ?tcenter1 ?tcenter2)
)

;;; carry: ?tcenter1 -> ?tcenter2
(declare-method CARRY-BETWEEN-TCENTERS(?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (n1  CARRY-DIRECT ?package ?tcenter1 ?tcenter2)
                     )
 ;         :effects (
  ;                  (n1 :delete (AT-PACKAGE ?package ?tcenter1))
   ;                 (n1 :assert (AT-PACKAGE ?package ?tcenter2)))
          :formula (and 
                       (not (veq ?tcenter1 ?tcenter2))
                       (initially (TYPE ?tcenter1 ?type1)  )
                       (not (veq ?type1 TCENTER))
                       (not (veq ?type1 HUB))
                       (initially (TYPE ?tcenter2 ?type1) )
                      )
)

;;; carry: ?tcenter1 (not hub) -> ?tcenter2 (not hub)
(declare-method CARRY-BETWEEN-TCENTERS(?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (n1  CARRY-VIA-HUB ?package  ?tcenter1 ?tcenter2)
                     )
 ;         :effects (
  ;                  (n1 :delete (AT-PACKAGE ?package ?tcenter1))
   ;                 (n1 :assert (AT-PACKAGE ?package ?tcenter2)))
	  :formula (and
		       (initially (~TYPE ?tcenter1 HUB) )
		       (initially (~TYPE ?tcenter2 HUB) )
                       (not (veq ?tcenter1 ?tcenter2))
                      )
)


;;; carry: ?tcenter1 -> ?hub -> ?tcenter2.  
(declare-method CARRY-VIA-HUB(?package ?tcenter1 ?tcenter2)
	  :expansion (
		      (n1  CARRY-DIRECT ?package ?tcenter1 ?hub)
		      (n2  CARRY-DIRECT ?package ?hub ?tcenter2)
                     )
;          :effects ( 
 ;                   (n1 :assert (AT-PACKAGE ?package ?hub) )
  ;                  (n1 :delete (AT-PACKAGE ?package ?tcenter1))
   ;                 (n2 :assert (AT_PACKAGE ?package ?tcenter2))
    ;                (n2 :delete (AT-PACKAGE ?package ?tcenter1)))
	  :formula (and
	               (ord n1 n2)
                       (initially (~TYPE ?package HAZARDOUS)  )
                       (initially (IN-CITY ?tcenter1 ?city1)  )
                       (initially (IN-CITY ?tcenter2 ?city2)  )
                       (initially (IN-REGION ?city1 ?region1) )
                       (initially (IN-REGION ?city2 ?region2) )
                       (initially (SERVES ?hub ?region1)  )
                       (initially (SERVES ?hub ?region2)  )
                       (initially (AVAILABLE ?hub)   )
                      )
)


;;; carry: ?tcenter1 -> ?hub -> ?tcenter2.  
(declare-method CARRY-VIA-HUB(?package ?tcenter1 ?tcenter2)
	  :expansion (
		      (n1  CARRY-DIRECT ?package ?tcenter1 ?hub)
		      (n2  CARRY-DIRECT ?package ?hub ?tcenter2)
                     )
;          :effects ( 
 ;                   (n1 :assert (AT-PACKAGE ?package ?hub) )
  ;                  (n1 :delete (AT-PACKAGE ?package ?tcenter1))
   ;                 (n2 :assert (AT_PACKAGE ?package ?tcenter2))
    ;                (n2 :delete (AT-PACKAGE ?package ?tcenter1)))
	  :formula (and
		       (ord n1 n2)
                       (initially (TYPE ?package HAZARDOUS)    )
                       (initially (PC-COMPATIBLE ?cityh HAZARDOUS)  )
                       (initially (IN-CITY ?tcenter1 ?city1)   )
                       (initially (IN-CITY ?tcenter2 ?city2)   )
                       (initially (IN-REGION ?city1 ?region1)  )
                       (initially (IN-REGION ?city2 ?region2)  )
                       (initially (SERVES ?hub ?region1)  )
                       (initially (SERVES ?hub ?region2)  )
                       (initially (IN-CITY ?hub ?cityh)   )
                       (initially (AVAILABLE ?hub)   )
                      )
)
;--------------------------
;  CARRY DECLARE-METHODS - DIRECT. 
;--------------------------

(declare-method CARRY-DIRECT(?package ?origin ?destination) 
          :expansion (
                      (n1  AT-VEHICLE ?vehicle ?origin)
                      (n2  LOAD-top   ?package ?vehicle ?origin)
                      (n3  AT-VEHICLE ?vehicle ?destination)
                      (n4  UNLOAD-top ?package ?vehicle ?destination)
                     )
          :formula(and
		     (ord n1 n2)
	             (ord n2 n3)
		     (ord n3 n4)
		     (before (AT-PACKAGE ?package ?origin)  n2)
                     (initially (TYPE ?package ?ptype)  )
                     (between  (AT-VEHICLE ?vehicle  ?origin)  n1 n2)
                     (between  (AT-PACKAGE ?package ?vehicle)  n2 n4)
                     (initially (AVAILABLE ?vehicle))
                     (initially (TYPE ?vehicle ?vtype)  )
                     (initially (PV-COMPATIBLE ?ptype ?vtype)  )
                     (or 
	         	  (and  ; same city via truck
			   (initially (TYPE ?vehicle TRUCK)  )
			   (initially (IN-CITY ?origin ?ocity)  )
			   (initially (IN-CITY ?destination ?ocity)))
			  (and  ;diff city via truck
			   (initially (TYPE ?vehicle TRUCK)  )
			   (initially (IN-CITY ?origin ?ocity)  )
			   (initially (IN-CITY ?destination ?dcity))
			   (initially (CONNECTS 
				       ?route ROAD-ROUTE  
				       ?ocity  ?dcity))
			   (initially (AVAILABLE ?route)    ))
			  (and  ;not truck
			   (initially (~TYPE ?vehicle TRUCK)  )
			   (initially (CONNECTS 
				       ?route ?rtype 
				       ?origin ?destination))
			   (initially (RV-COMPATIBLE ?rtype ?vhtype))
			   (initially (TYPE ?vehicle ?vhtype)  )
			   (initially (AVAILABLE ?route)  )))
                     )
)

		

;--------------------------------
;  MOVE VEHICLE DECLARE-METHODS
;--------------------------------

;;; move: ?origin -> ?location, via road
(declare-method AT-VEHICLE(?vehicle ?location) 
    :expansion(
	       (n1  MOVE-VEHICLE ?vehicle  ?origin ?location ?r)
	       )
    :formula (and
	      (before (AT-VEHICLE ?vehicle  ?origin)  n1)
	      (initially (TYPE ?vehicle TRUCK)  )
	      (initially (IN-CITY ?origin ?ocity)  )
	      (or
	       (and ; same city
		(veq ?r LOCAL-ROAD-ROUTE)
		(initially (IN-CITY ?location ?ocity)  ))
	       (and ;different city
		(initially (IN-CITY ?location ?dcity) )
		(initially (CONNECTS ?r ROAD-ROUTE ?ocity ?dcity)  ))
	       ))
)
 
 
;;; move: ?origin -> ?location                 	
(declare-method AT-VEHICLE(?vehicle ?location) 
    :expansion (
		(n1  MOVE-VEHICLE ?vehicle  ?origin ?location ?r)
		)
    :formula (and
	      (initially (~TYPE ?vehicle TRAINCAR)  )
	      (before (AT-VEHICLE ?vehicle  ?origin)  n1)
	      (initially (TYPE ?vehicle ?vtype)  )
	      (initially (CONNECTS ?r ?rtype  ?origin ?location)  )
	      (initially (RV-COMPATIBLE ?rtype ?vtype)  )
	      )
    )				

;--------------------
;  TRAIN CAR DECLARE-METHODS
;--------------------

;;; send train to pickup car, deliver it to destination, and detach it	    
(declare-method AT-VEHICLE(?tc ?destination) 
    :expansion (
		(n1  AT-VEHICLE  ?train ?origin)
		(n2  ATTACH-TRAIN-CAR ?train ?tc ?origin)
		(n3  AT-VEHICLE ?train ?destination)
		(n4  DETACH-TRAIN-CAR ?train ?tc ?destination)
		)
    :formula (and
	      (ord n1 n2)
	      (ord n2 n3)
	      (ord n3 n4)
	      (initially (TYPE ?tc  TRAINCAR)  )
	      (before (AT-VEHICLE ?tc ?origin)  n2)
	      (initially (CONNECTS ?r RAIL-ROUTE ?origin ?destination))
	      (initially (TYPE ?train TRAIN)  )
	      (between (AT-VEHICLE ?tc ?train )  n2 n4)
	      (between (AT-VEHICLE ?train ?origin)  n1 n2)
	      (between (AT-VEHICLE ?train ?destination)  n3 n4 )
	      )
)				

;\end{verbatim}

