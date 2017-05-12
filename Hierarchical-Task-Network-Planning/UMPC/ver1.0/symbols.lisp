;\begin{verbatim}

(in-package "UMCP")

(VARIABLES 
     ?v ?p ?l ?c ?r ?ol ?dl ?t
     ?package ?origin ?destination ?location ?region1 ?region2
     ?hub ?ocity ?dcity ?city1 ?city2 ?cityh ?samecity ?tcenter
     ?tcenter1 ?tcenter2 ?tt ?vehicle ?tc ?train ?ptype ?vtype ?route
     ?r ?rtype ?vptype ?type1 ?vhtype)

(CONSTANTS 
        air-route mail perishable refrigerated granular airplane
        armored auto bulky cars
	city1 city1-cl1 city1-cl2 city1-ts1
        city1-ts2 city1-ap1 city1-ap2 city2 city2-cl1 city2-ap1
        city2-ts1 region1 region2 city3 city3-cl1 city3-ap1 city3-ts1
        region1-ap1 region1-ts1 rail-route-1 rail-route-2 rail-route-3
        rail-route-4 road-route-1 road-route-2 air-route-1 air-route-2
        air-route-3 air-route-4 ramp1a ramp1b ramp2 ramp3 ramp4
        road-route-i1547 road-route-i1548 pkg-1 truck-1 not-tcenter
        not-hub train-station tcenter hub not-hazardous not-traincar
        clocation tcenter airport train-station city region crane
        flatbed hazardous hopper hub livestock liquid local-road-route
        plane-ramp rail-route air-route regular road-route tanker
        train traincar truck tcenter valuable)

(PRIMITIVE-TASKS 
        affix-warning-signs attach-conveyor-ramp
	attach-train-car close-door close-valve collect-fees
	collect-insurance connect-chute connect-hose
	decontaminate-interior deliver detach-conveyor-ramp
	detach-train-car disconnect-chute disconnect-hose
	do-clean-interior do-nothing empty-hopper empty-tank
	fill-hopper fill-tank fill-trough load-cars load-livestock
	load-package lower-ramp move-vehicle obtain-permit open-door
	open-valve pick-up-package-ground pick-up-package-vehicle
	post-guard-inside post-guard-outside put-down-package-ground
	put-down-package-vehicle raise-ramp remove-guard
	remove-warning-signs unload-cars unload-livestock
	unload-package )



(PREDICATES 
        (at-equipment 15) (at-package 100) (at-vehicle 40)
	available chute-connected clean-interior connects
	decontaminated-interior door-open empty fees-collected
	guard-inside guard-outside have-permit hose-connected in-city
	in-region insured pc-compatible pv-compatible ramp-available
	ramp-connected ramp-down rv-compatible serves trough-full type
	valve-open warning-signs-affixed
)




(COMPOUND-TASKS 
        (carry 79) (carry-between-tcenters 75) (carry-direct 70) 
        (carry-via-hub 78) handle-hazardous handle-insurance
        (load-top 25) (unload-top 25) (load-haz 22) (load-val 22)
        (unload-haz 22) (unload-val 22) (load 20) pickup 
	(transport 90)(unload 20) 
)


