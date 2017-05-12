(in-package "UMCP")
;LOAD TRANSLOG DOMAIN 
;MUST BE LOADED ONLY AFTER UMCP HAS BEEN LOADE

(defparameter *load-path* "/fs/scruffy/reiko/umcp2-22/Translog/")

(umcp::clear-domain)
(load (concatenate 'string *load-path* "symbols.lisp"))
(load (concatenate 'string *load-path* "actions.lisp"))
(load (concatenate 'string *load-path* "predmethods.lisp"))
(load (concatenate 'string *load-path* "load-methods.lisp"))
(load (concatenate 'string *load-path* "main-methods.lisp"))
(umcp::load-poss-effects-table)
(load (concatenate 'string *load-path* "initial-state.lisp"))

 
