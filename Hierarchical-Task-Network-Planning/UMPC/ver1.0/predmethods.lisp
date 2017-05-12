;\begin{verbatim}
(in-package "UMCP")

(declare-method door-open (?v)
	:expansion ((n1 open-door ?v)))
(declare-method ~door-open (?v)
	:expansion ((n1 close-door ?v)))

;--------------------------------------------

(declare-method chute-connected(?v)
	:expansion((n1 connect-chute ?v)))
(declare-method ~chute-connected(?v)
	:expansion((n1 disconnect-chute ?v)))

;--------------------------------------------

(declare-method hose-connected(?v)
	:expansion((n1 connect-hose ?v)))
(declare-method ~hose-connected(?v)
	:expansion((n1 disconnect-hose ?v)))

;--------------------------------------------

(declare-method valve-open(?v)
	:expansion ((n1 open-valve ?v)))
(declare-method ~valve-open(?v)
	:expansion ((n1 close-valve ?v)))

;--------------------------------------------

(declare-method ramp-down(?v)
	:expansion((n1 lower-ramp ?v)))
(declare-method ~ramp-down(?v)
	:expansion((n1 raise-ramp ?v)))

;--------------------------------------------

(declare-method trough-full(?v)
	:expansion((n fill-trough ?v)))

;--------------------------------------------

(declare-method clean-interior(?v)
	:expansion((n do-clean-interior ?v)))


;--------------------------------------------

(declare-method ramp-connected(?v ?r ?l)
	:expansion((n attach-conveyor-ramp ?v ?r ?l)))
(declare-method ~ramp-connected(?v ?r ?l)
	:expansion((n detach-conveyor-ramp ?v ?r ?l)))

;--------------------------------------------

(declare-method guard-outside(?v)
	:expansion( (n post-guard-outside ?v)))
(declare-method ~guard-outside(?v)
	:expansion( (n remove-guard ?v)))
(declare-method guard-inside(?v)
	:expansion( (n post-guard-inside ?v)))

;--------------------------------------------

(declare-method warning-signs-affixed  (?v)
	:expansion ( (n affix-warning-signs ?v)))
(declare-method ~warning-signs-affixed  (?v)
	:expansion ( (n remove-warning-signs ?v)))

;--------------------------------------------

(declare-method decontaminated-interior (?v)
		:expansion ((n decontaminate-interior ?v)))


;\end{verbatim}