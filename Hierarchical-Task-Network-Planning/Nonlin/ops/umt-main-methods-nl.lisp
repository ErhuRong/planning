;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;;    Application:  UM Nonlin 1.3
;;;;
;;;;           File:  UMT-MAIN-METHODS-NL.LISP
;;;;       Contents:  Nonlin schema defns for Main Methods in the UM-Translog domain.
;;;;
;;;;         Author:  K. Erol, B. Kettler
;;;;
;;;;                  Dept. of Computer Science, University of Maryland at College Park
;;;;
;;;;       Language:  Macintosh Common Lisp 2.0
;;;;
;;;;   Requirements:  Files loaded in order: 1) UMT-MAIN-METHODS-NL
;;;;                                         2) UMT-LOAD-METHODS-NL
;;;;                                         3) UMT-ACTIONS-NL.LISP
;;;;
;;;;  History:
;;;;  Date      Who  Modification
;;;;  -----------------------------------------------------------------------------------   
;;;;   6/06/95  bpk  replaced (UN)LOAD-VALUABLE with (UN)LOAD-VAL, (UN)LOAD-HAZ-VAL.
;;;;                 added LOAD-TOP, UNLOAD-TOP (called by CARRY-DIRECTS instead of (UN)LOAD)
;;;;   6/05/95       changed package specifier and commented out lines
;;;;   7/21/94       modified for domain spec. version 4
;;;;   7/18/94       replaced :use-only-for-query conditions with :use-when conditions
;;;;   6/15/94       created

(reset-schematable)

(setq *autocond* nil)

;;; top-level method: used for top-level goal
(opschema transportation-job
   :todo (AT-PACKAGE ?package ?destination)
   :expansion (
               (s1 :action (TRANSPORT ?package ?origin ?destination))
              )
   :conditions (
                (:use-when (AT-PACKAGE ?package ?origin) :at s1)
               )
   :variables (?package ?origin ?destination)
)


(opschema tr-method
          :todo (TRANSPORT ?package ?origin ?destination)
          :expansion (
		      (s1 :action (PICKUP  ?package))
 		      (s2 :action (CARRY   ?package ?origin ?destination))
 		      (s3 :action (DO-DELIVER ?package))
                     )
          :orderings ((-> s1 s2 s3))
          :effects (
                    (s2 :delete (AT-PACKAGE ?package ?origin))
                    (s2 :assert (AT-PACKAGE ?package ?destination))
                    )
          :variables (?package ?origin ?destination)
)


;--------------------------------------------------------------------------------------
; PICKUP METHODS
;--------------------------------------------------------------------------------------

(opschema pickup-method
          :todo (PICKUP ?package)  
          :expansion (
                     (s1 :action (FEES-COLLECTED   ?package))
                     (s2 :action (HANDLE-INSURANCE ?package))
                     (s3 :action (HANDLE-HAZARDOUS ?package)))
           :variables (?package)
)

;--------------------------------------------------------------------------------------

(opschema insurance-method
          :todo (HANDLE-INSURANCE ?package)  
          :expansion (
                      (s1 :action (INSURED ?package))
                     )
          :conditions (
		       (:use-when (TYPE ?package VALUABLE) :at s1)
                      )
          :variables (?package)
)

(opschema insurance-method2
          :todo (HANDLE-INSURANCE ?package)  
          :expansion (
                      (s1 :primitive (DO-NOTHING))
                     )
          :conditions (
		       (:use-when (TYPE ?package NOT-VALUABLE) :at s1)
                      )
          :variables (?package)
)

;--------------------------------------------------------------------------------------

(opschema hazardous-method
          :todo (HANDLE-HAZARDOUS ?package)  
          :expansion (
                      (s1 :action (HAVE-PERMIT ?package))
                     )
          :conditions (
		       (:use-when (TYPE ?package HAZARDOUS) :at s1)
                      )
          :variables (?package)
)

(opschema hazardous-method2
          :todo (HANDLE-HAZARDOUS ?package)  
          :expansion (
                      (s1 :primitive (DO-NOTHING))
                     )
          :conditions (
		       (:use-when (TYPE ?package NOT-HAZARDOUS) :at s1)
                      )
          :variables (?package)
)
					

;---------------------------------------------------------------------------------------
;  CARRY METHODS - TOP LEVEL.  ** THESE BIND TCENTERS **
;---------------------------------------------------------------------------------------

;;; top-level carry method
(opschema simple-carry-method 
          :todo (CARRY ?package ?origin ?destination)  
          :expansion (
                      (s1 :action (CARRY-DIRECT ?package ?origin ?destination))
                     )
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?origin))
                    (s1 :assert (AT-PACKAGE ?package ?destination))
                    )
  
          :variables (?package ?origin ?destination)
)

;;; carry: ?origin (tcenter, not hub) -> ?destination (tcenter, not hub)	
(opschema carry-method-b 
          :todo (CARRY ?package  ?origin  ?destination)  
          :expansion (
                      (s1 :action (CARRY-VIA-HUB ?package ?origin ?destination))
                     ) 
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?origin))
                    (s1 :assert (AT-PACKAGE ?package ?destination))
                    )
  
          :conditions (
                       (:use-when (IN-CITY ?origin      ?ocity) :at s1)
                       (:use-when (IN-CITY ?destination ?dcity) :at s1)
                       (:use-when (not (equal ?ocity ?dcity)) :at s1)
                       (:use-when (TYPE ?origin      TCENTER) :at s1)
                       (:use-when (TYPE ?destination TCENTER) :at s1)
                       (:use-when (TYPE ?origin      NOT-HUB) :at s1)
                       (:use-when (TYPE ?destination NOT-HUB) :at s1)
                       (:use-when (AVAILABLE ?origin)      :at s1)
                       (:use-when (AVAILABLE ?destination) :at s1)
                      )
          :variables (?package ?origin ?destination ?ocity ?dcity)
)

;;; carry: ?origin (not tcenter) -> ?tcenter -> ?destination (tcenter)
(opschema carry-method-db 
          :todo (CARRY ?package ?origin ?destination)  
          :expansion (
		      (s0 :action (CARRY-DIRECT ?package ?origin ?tcenter))
                      (s1 :action (CARRY-BETWEEN-TCENTERS ?package ?tcenter ?destination))
                     )     
          :effects (
                    (s0 :delete (AT-PACKAGE ?package ?origin))
                    (s0 :assert (AT-PACKAGE ?package ?tcenter))
                    (s1 :delete (AT-PACKAGE ?package ?tcenter))
                    (s1 :assert (AT-PACKAGE ?package ?destination))
                    )
  
          :orderings ((s0 -> s1))
          :conditions (
                       (:use-when (TYPE ?origin      NOT-TCENTER) :at s1)
                       (:use-when (TYPE ?destination TCENTER)     :at s1)
                       (:use-when (IN-CITY ?origin ?ocity)      :at s1)
                       (:use-when (IN-CITY ?destination ?dcity) :at s1)
                       (:use-when (not (equal ?ocity ?dcity))         :at s1)
                       (:use-when (SERVES ?tcenter ?ocity) :at s1) ; *** new
                       (:use-when (TYPE ?tcenter TCENTER) :at s0)
	               (:use-when (not (equal ?tcenter ?destination) ) :at s0)
                       (:use-when (TYPE ?tcenter ?tt) :at s0)
                       (:use-when (not (equal ?tt TCENTER)) :at s0)
                       (:use-when (TYPE ?destination ?tt) :at s0)
                       (:use-when (AVAILABLE ?tcenter)     :at s0)
                       (:use-when (AVAILABLE ?destination) :at s0)                      
                      )
          :variables (?package ?origin ?destination ?ocity ?dcity ?tcenter  ?tt)
)

;;; carry: ?origin (tcenter) -> ?tcenter -> ?destination (not tcenter)
(opschema carry-method-bd 
          :todo (CARRY ?package ?origin ?destination)  
          :expansion (
		      (s1 :action (CARRY-BETWEEN-TCENTERS ?package  ?origin ?tcenter))
		      (s2 :action (CARRY-DIRECT ?package  ?tcenter ?destination))
                     ) 
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?origin))
                    (s1 :assert (AT-PACKAGE ?package ?tcenter))
                    (s2 :delete (AT-PACKAGE ?package ?tcenter))
                    (s2 :assert (AT-PACKAGE ?package ?destination))
                    )
          :orderings ((s1 -> s2))
          :conditions (
                       (:use-when (TYPE ?origin      TCENTER)     :at s1)
                       (:use-when (TYPE ?destination NOT-TCENTER) :at s1)
                       (:use-when (IN-CITY ?origin ?ocity) :at s1)
                       (:use-when (IN-CITY ?destination ?dcity) :at s1)
                       (:use-when (not (equal ?ocity ?dcity))      :at s1)
                       (:use-when (SERVES ?tcenter ?dcity) :at s1) ; *** new
	               (:use-when (TYPE ?tcenter TCENTER) :at s1)
                       (:use-when (TYPE ?tcenter ?tt) :at s1)
                       (:use-when (not (equal ?tt TCENTER)) :at s1)
                       (:use-when (TYPE ?origin ?tt) :at s0)
                      
                       (:use-when (not (equal ?tcenter ?origin) :at s1))
                       (:use-when (AVAILABLE ?origin)      :at s1)
                       (:use-when (AVAILABLE ?tcenter)     :at s1)
                      )
          :variables (?package ?origin ?destination ?ocity ?dcity ?tcenter  ?tt)
)

;;; carry: ?origin (not tcenter) -> ?tcenter1 -> ?tcenter2 -> ?destination (not tcenter)
(opschema carry-method-dbd
          :todo (CARRY ?package  ?origin  ?destination)  
          :expansion (
		      (s0 :action (CARRY-DIRECT ?package  ?origin   ?tcenter1))
                      (s1 :action (CARRY-BETWEEN-TCENTERS ?package  ?tcenter1 ?tcenter2))
                      (s2 :action (CARRY-DIRECT ?package  ?tcenter2 ?destination))
                     )
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s1 :assert (AT-PACKAGE ?package ?tcenter2))
                    (s0 :delete (AT-PACKAGE ?package ?origin))
                    (s0 :assert (AT-PACKAGE ?package ?tcenter1))
                    (s2 :assert (AT-PACKAGE ?package ?destination))
                    (s2 :delete (AT-PACKAGE ?package ?tcenter2)))

          :orderings ((-> s0 s1 s2))
          :conditions (
                       (:use-when (TYPE ?origin      NOT-TCENTER) :at s1)
                       (:use-when (TYPE ?destination NOT-TCENTER) :at s1)
                       
                       (:use-when (IN-CITY ?origin ?ocity)      :at s1)
                       (:use-when (IN-CITY ?destination ?dcity) :at s1)
                       (:use-when (not (equal ?ocity ?dcity)) :at s1)
                       (:use-when (SERVES ?tcenter1 ?ocity) :at s1) ; *** new
                       (:use-when (SERVES ?tcenter2 ?dcity) :at s1) ; *** new
	               (:use-when (TYPE ?tcenter1 TCENTER) :at s1)
                       (:use-when (TYPE ?tcenter1 ?tt) :at s0)
                       (:use-when (not (equal ?tt TCENTER)) :at s0)
                       (:use-when (TYPE ?tcenter2 ?tt) :at s0)
                      
	               (:use-when (TYPE ?tcenter2 TCENTER) :at s1)
                       (:use-when (AVAILABLE ?tcenter1) :at s0)
                       (:use-when (AVAILABLE ?tcenter2) :at s0)                      
                      )
          :variables (?package ?origin ?destination ?ocity ?dcity ?tcenter1 ?tcenter2  ?tt)
)
					
;---------------------------------------------------------------------------------------
;  CARRY METHODS - BETWEEN TCENTERS.  ** THESE BIND HUB (IF APPLIC.) **
;---------------------------------------------------------------------------------------

;;; carry: ?tcenter1 -> ?tcenter2 where ?tcenter1 = ?tcenter2
(opschema between-tcenters-same
          :todo (CARRY-BETWEEN-TCENTERS ?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (s1 :primitive (DO-NOTHING)))
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s1 :assert (AT-PACKAGE ?package ?tcenter2)))

          :conditions( (:use-when (equal ?tcenter1 ?tcenter2) :at s1))
          :variables(?package ?tcenter1 ?tcenter2) 
)

;;; carry: ?tcenter1 -> ?tcenter2
(opschema between-tcenters-direct
	  :todo (CARRY-BETWEEN-TCENTERS ?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (s1 :action (CARRY-DIRECT ?package ?tcenter1 ?tcenter2))
                     )
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s1 :assert (AT-PACKAGE ?package ?tcenter2)))

          :conditions ((:use-when (not (equal ?tcenter1 ?tcenter2) :at s1))
                       (:use-when (TYPE ?tcenter1 ?type1) :at s1)
                       (:use-when (not (equal ?type1 TCENTER)) :at s1)
                       (:use-when (not (equal ?type1 HUB)) :at s1) 
                       (:use-when (not (equal ?type1 NOT-HUB)) :at s1)
                       (:use-when (TYPE ?tcenter2 ?type1) :at s1)
                      )
	  :variables (?package ?tcenter1 ?tcenter2) 
)

;;; carry: ?tcenter1 (not hub) -> ?tcenter2 (not hub)
(opschema between-tcenters-via-hub
	  :todo (CARRY-BETWEEN-TCENTERS ?package ?tcenter1 ?tcenter2) 
	  :expansion (
		      (s1 :action (CARRY-VIA-HUB ?package  ?tcenter1 ?tcenter2))
                     )
          :effects (
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s1 :assert (AT-PACKAGE ?package ?tcenter2)))

	  :conditions (
		       (:use-when (TYPE ?tcenter1 NOT-HUB) :at s1)
		       (:use-when (TYPE ?tcenter2 NOT-HUB) :at s1)
                       (:use-when (not (equal ?tcenter1 ?tcenter2) :at s1))
                      )
	  :variables (?package  ?tcenter1 ?tcenter2) 
)


;;; carry: ?tcenter1 -> ?hub -> ?tcenter2.  ** BINDS ?hub **  (NONHAZARDOUS PACKAGES)		
(opschema via-hub-method
	  :todo (CARRY-VIA-HUB ?package ?tcenter1 ?tcenter2)
	  :expansion (
		      (s1 :action (CARRY-DIRECT ?package ?tcenter1 ?hub))
		      (s2 :action (CARRY-DIRECT ?package ?hub ?tcenter2))
                     )
          :orderings ((-> s1 s2))
          :effects ( 
                    (s1 :assert (AT-PACKAGE ?package ?hub) )
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s2 :assert (AT_PACKAGE ?package ?tcenter2))
                    (s2 :delete (AT-PACKAGE ?package ?tcenter1)))
	  :conditions (
                       (:use-when (TYPE ?package NOT-HAZARDOUS) :at s1)
                       (:use-when (IN-CITY ?tcenter1 ?city1)  :at s1)
                       (:use-when (IN-CITY ?tcenter2 ?city2)  :at s1)
                       (:use-when (IN-REGION ?city1 ?region1) :at s1)
                       (:use-when (IN-REGION ?city2 ?region2) :at s1)
                       (:use-when (SERVES ?hub ?region1) :at s1)
                       (:use-when (SERVES ?hub ?region2) :at s1)
                       (:use-when (AVAILABLE ?hub)  :at s1)
                      )
	  :variables (?package ?tcenter1 ?tcenter2 ?city1 ?city2 ?region1 ?region2 ?hub) 
)


;;; carry: ?tcenter1 -> ?hub -> ?tcenter2.  ** BINDS ?hub **  (HAZARDOUS PACKAGES)
(opschema via-hub-method-hazardous
	  :todo (CARRY-VIA-HUB ?package ?tcenter1 ?tcenter2)
	  :expansion (
		      (s1 :action (CARRY-DIRECT ?package ?tcenter1 ?hub))
		      (s2 :action (CARRY-DIRECT ?package ?hub ?tcenter2))
                     )
          :orderings ((-> s1 s2))
          :effects ( 
                    (s1 :assert (AT-PACKAGE ?package ?hub) )
                    (s1 :delete (AT-PACKAGE ?package ?tcenter1))
                    (s2 :assert (AT_PACKAGE ?package ?tcenter2))
                    (s2 :delete (AT-PACKAGE ?package ?tcenter1)))
	  :conditions (
                       (:use-when (TYPE ?package HAZARDOUS)   :at s1)
                       (:use-when (PC-COMPATIBLE ?cityh HAZARDOUS) :at s1)
                       (:use-when (IN-CITY ?tcenter1 ?city1)  :at s1)
                       (:use-when (IN-CITY ?tcenter2 ?city2)  :at s1)
                       (:use-when (IN-REGION ?city1 ?region1) :at s1)
                       (:use-when (IN-REGION ?city2 ?region2) :at s1)
                       (:use-when (SERVES ?hub ?region1) :at s1)
                       (:use-when (SERVES ?hub ?region2) :at s1)
                       (:use-when (IN-CITY ?hub ?cityh)  :at s1)
                       (:use-when (AVAILABLE ?hub)  :at s1)
                      )
	  :variables (?package ?tcenter1 ?tcenter2 ?city1 ?city2 ?region1 ?region2 ?hub) 
)

;---------------------------------------------------------------------------------------
;  CARRY METHODS - DIRECT. ** THESE BIND VEHICLES AND DIRECT ROUTES **
;---------------------------------------------------------------------------------------

;;; carry: ?origin -> ?destination, where ?origin and ?destination are in same city.
(opschema carry-direct-method-same-city
          :todo (CARRY-DIRECT ?package ?origin ?destination) 
          :expansion (
                      (s1 :goal   (AT-VEHICLE ?vehicle ?origin))
                      (s2 :action (LOAD-TOP   ?package ?vehicle ?origin))
                      (s3 :goal   (AT-VEHICLE ?vehicle ?destination))
                      (s4 :action (UNLOAD-TOP ?package ?vehicle ?destination))
                     )
          :effects (
                    (s1 :assert (AT-VEHICLE ?vehicle ?origin))
                    (s2 :delete (AT-PACKAGE ?package ?origin))
                    (s2 :assert (AT-PACKAGE ?package ?vehicle))
                    (s3 :delete (AT-VEHICLE ?vehicle ?origin))
                    (s3 :assert (AT-VEHICLE ?vehicle ?destination))
                    (s4 :delete (AT-PACKAGE ?package ?vehicle))
                    (s4 :assert (AT-PACKAGE ?package ?destination))  )
          :orderings ((-> s1 s2 s3 s4))
          :conditions (
                       (:use-when (IN-CITY ?origin ?ocity) :at s1)
                       (:use-when (IN-CITY ?destination ?ocity) :at s1)
                       (:use-when (AT-PACKAGE ?package ?origin) :at s2)
                       (:use-when (TYPE ?vehicle TRUCK) :at s1)
                       (:use-when (TYPE ?package ?ptype) :at s1)
                       (:use-when (TYPE ?vehicle ?vtype) :at s1)
                       (:use-when (PV-COMPATIBLE ?ptype ?vtype) :at s1)
                       (:precond  (AT-VEHICLE ?vehicle  ?origin) :at s2 :from s1)
                       (:precond  (AT-PACKAGE ?package ?vehicle) :at s4 :from s2)
                       (:use-when (AVAILABLE ?vehicle) :at s1)
                      )
          :variables (?package ?origin ?destination ?ocity ?vehicle ?ptype ?vtype)
)

;;; carry: ?origin (in ?ocity) -(ROAD)-> ?destination (in ?dcity)
(opschema carry-direct-method-diff-city-road
          :todo (CARRY-DIRECT ?package  ?origin  ?destination) 
          :expansion (
                      (s1 :goal   (AT-VEHICLE ?vehicle ?origin))
                      (s2 :action (LOAD-TOP   ?package ?vehicle ?origin)  )
                      (s3 :goal   (AT-VEHICLE ?vehicle ?destination))
                      (s4 :action (UNLOAD-TOP ?package ?vehicle ?destination)))
          :effects (
                    (s1 :assert (AT-VEHICLE ?vehicle ?origin))
                    (s2 :delete (AT-PACKAGE ?package ?origin))
                    (s2 :assert (AT-PACKAGE ?package ?vehicle))
                    (s3 :delete (AT-VEHICLE ?vehicle ?origin))
                    (s3 :assert (AT-VEHICLE ?vehicle ?destination))
                    (s4 :delete (AT-PACKAGE ?package ?vehicle))
                    (s4 :assert (AT-PACKAGE ?package ?destination))  )
          :orderings ((-> s1 s2 s3 s4))
          :conditions (
                       
                       (:use-when (AT-PACKAGE  ?package  ?origin) :at s2)
                       (:use-when (IN-CITY ?origin ?ocity) :at s1)
                       (:use-when (IN-CITY ?destination ?dcity) :at s1)
                       (:use-when (CONNECTS ?route ROAD-ROUTE  ?ocity  ?dcity) :at s1)
                       (:use-when (TYPE ?vehicle TRUCK) :at s1)
                       (:use-when (TYPE ?package ?ptype) :at s1)
                       (:use-when (TYPE ?vehicle ?vtype) :at s1)
                       (:use-when (PV-COMPATIBLE ?ptype ?vtype) :at s1)
                       (:precond  (AT-VEHICLE ?vehicle  ?origin) :at s2 :from s1)
                       (:precond  (AT-PACKAGE ?package ?vehicle) :at s4 :from s2)
                       (:use-when (AVAILABLE ?vehicle) :at s1)
                       (:use-when (AVAILABLE ?route)   :at s1)
                      )
          :variables (?package ?origin ?destination ?vehicle ?ocity  ?dcity ?route ?vtype ?ptype)
)

;;; carry: ?origin (in ?ocity) -(RAIL or AIR)-> ?destination (in ?dcity)
(opschema carry-direct-method-diff-city-not-road
          :todo (CARRY-DIRECT ?package  ?origin  ?destination) 
          :expansion (
                      (s1 :goal   (AT-VEHICLE ?vehicle ?origin ))
                      (s2 :action (LOAD-TOP   ?package ?vehicle ?origin))
                      (s3 :goal   (AT-VEHICLE ?vehicle ?destination))
                      (s4 :action (UNLOAD-TOP ?package ?vehicle ?destination))
                     )
          :effects (
                    (s2 :delete (AT-PACKAGE ?package ?origin))
                    (s2 :assert (AT-PACKAGE ?package ?vehicle))
                    (s3 :delete (AT-VEHICLE ?vehicle ?origin))
                    (s4 :delete (AT-PACKAGE ?package ?vehicle))
                    (s4 :assert (AT-PACKAGE ?package ?destination))  )
           :orderings ((-> s1 s2 s3 s4))
          :conditions (
                       (:use-when (AT-PACKAGE  ?package  ?origin) :at s2)
                       (:use-when (TYPE ?package ?ptype) :at s1)
                       (:use-when (CONNECTS ?route ?rtype  ?origin  ?destination) :at s1)
                       (:use-when (RV-COMPATIBLE ?rtype ?vtype) :at s1)
                       (:use-when (TYPE ?vehicle ?vtype) :at s1)
                       (:use-when (TYPE ?vehicle ?vptype) :at s1)
                       (:use-when (PV-COMPATIBLE ?ptype ?vptype) :at s1)
                       (:precond  (AT-VEHICLE ?vehicle  ?origin) :at s2 :from s1)
                       (:precond  (AT-PACKAGE ?package  ?vehicle) :at s4 :from s2)
                       (:use-when (AVAILABLE ?vehicle) :at s1)
                       (:use-when (AVAILABLE ?route)   :at s1)
                      )
          :variables (?package ?origin ?destination ?vehicle ?route ?rtype ?vtype ?vptype)
)
		

;------------------------------------------------------------------------------------------------------------
;  MOVE VEHICLE METHODS
;------------------------------------------------------------------------------------------------------------

;;; move: ?origin -> ?location, where ?origin and ?location in same city
(opschema move-vehicle-same-city
	  :todo (AT-VEHICLE ?vehicle ?location) 
	  :expansion (
                      (s1 :action (DO-MOVE-VEHICLE ?vehicle  ?origin ?location LOCAL-ROAD-ROUTE))
                     )
          :effects (
                    (s1 :assert (AT-VEHICLE ?vehicle  ?location))
                    (s1 :delete (AT-VEHICLE ?vehicle  ?origin)))
	  :conditions (
		       (:use-when (AT-VEHICLE ?vehicle  ?origin) :at s1)
		       (:use-when (TYPE ?vehicle TRUCK) :at s1)
                       (:use-when (IN-CITY ?origin ?samecity) :at s1)
		       (:use-when (IN-CITY ?location ?samecity) :at s1)
                      )
          :variables (?vehicle ?location ?origin ?samecity )
)
 
;;; move: ?origin -(ROAD)-> ?location, where ?origin and ?location in same city
(opschema move-vehicle-diff-city-road-route
	  :todo (AT-VEHICLE ?vehicle ?location) 
	  :expansion (
                      (s1 :action (DO-MOVE-VEHICLE ?vehicle  ?origin ?location ?r))
                     )
          :effects (
                    (s1 :assert (AT-VEHICLE ?vehicle  ?location))
                    (s1 :delete (AT-VEHICLE ?vehicle  ?origin)))
	  :conditions (
		       (:use-when (AT-VEHICLE ?vehicle  ?origin) :at s1)
		       (:use-when (TYPE ?vehicle TRUCK) :at s1)
                       (:use-when (IN-CITY ?origin ?ocity) :at s1)
		       (:use-when (IN-CITY ?location ?dcity) :at s1)
                       (:use-when (CONNECTS ?r ROAD-ROUTE ?ocity ?dcity) :at s1)
                      )
          :variables (?vehicle ?location ?origin ?ocity ?dcity ?r)
)
 
;;; move: ?origin -> ?location                 	
(opschema move-vehicle-direct-not-train-car
	  :todo (AT-VEHICLE ?vehicle ?location) 
	  :expansion (
                      (s1 :action (DO-MOVE-VEHICLE ?vehicle  ?origin ?location ?r))
                     )
          :effects ( (s1 :assert (AT-VEHICLE ?vehicle ?location))
                     (s1 :delete (AT-VEHICLE ?vehicle ?origin)))
	  :conditions (
		       (:use-when (TYPE ?vehicle NOT-TRAINCAR) :at s1)
		       (:use-when (AT-VEHICLE ?vehicle  ?origin) :at s1)
		       (:use-when (TYPE ?vehicle ?vtype) :at s1)
                       (:use-when (CONNECTS ?r ?rtype  ?origin ?location) :at s1)
		       (:use-when (RV-COMPATIBLE ?rtype ?vtype) :at s1)
                      )
          :variables (?vehicle ?location ?origin ?vtype ?r ?rtype)
)				

;---------------------------------------------------------------------------------
;  TRAIN CAR METHODS
;---------------------------------------------------------------------------------

;;; send train to pickup car, deliver it to destination, and detach it		
(opschema train-car-to-loc
	  :todo (AT-VEHICLE ?tc ?destination) 
	  :expansion (
	       	      (s1 :goal (AT-VEHICLE  ?train ?origin))
                      (s2 :action (DO-ATTACH-TRAINCAR ?train ?tc))
		      (s3 :goal (AT-VEHICLE ?train ?destination))
	              (s4 :action (DO-DETACH-TRAINCAR ?train ?tc))
                     )
          :effects (
                    (s2 :delete (AT-VEHICLE ?tc ?origin))
                    (s2 :assert (AT-VEHICLE ?tc ?train))
                    (s3 :delete (AT-VEHICLE ?train ?origin))
                    (s4 :delete (AT-VEHICLE ?tc ?train))
                    (s4 :assert (AT-VEHICLE ?tc ?destination)) )
	  :orderings ((->  s1 s2 s3 s4))
	  :conditions (
		       (:use-when (TYPE ?tc  TRAINCAR) :at s1)
                       (:use-when (AT-VEHICLE ?tc ?origin) :at s2)
                       (:use-when (CONNECTS ?r RAIL-ROUTE ?origin ?destination) :at s1)
                       (:use-when (TYPE ?train TRAIN) :at s1)
                       (:precond (AT-VEHICLE ?tc ?train ) :at s4 :from s2)
		       (:precond (AT-VEHICLE ?train ?origin) :at s2 :from s1)
		       (:precond (AT-VEHICLE ?train ?destination) :at s4 :from s3)
                      )
          :variables (?tc ?train ?origin ?destination ?r )
)				

