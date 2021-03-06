;;; bw-large-b
;;;
;;; Initial:  C/B/A   K/J/E/D/   I/H/G/F
;;; Goal:     A/E/J/  H/I/D/   B/C/K/G/F
;;; Length:   AH

(define (problem bw-large-b)
  (:domain prodigy-bw)
  (:objects A B C D E F G H I J K)
  (:init (arm-empty)
	 (on C B)
	 (on B A)
	 (on-table A)
	 (on K J)
	 (on J E)
	 (on E D)
	 (on-table D)
	 (on I H)
	 (on H G)
	 (on G F)
	 (on-table F)
	 (clear C)
	 (clear K)
	 (clear I))
  (:goal (and
	  (on A E)
	  (on E J)
	  (on-table J)
	  (on H I)
	  (on I D)
	  (on-table D)
	  (on B C)
	  (on C K)
	  (on K G)
	  (on G F)
	  (on-table F)
	  (clear A)
	  (clear H)
	  (clear B)
	  )))
