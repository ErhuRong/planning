;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;
;;;; UM Nonlin - University of Maryland at College Park 
;;;;
;;;; Version 1.2.2, 11/92
;;;; (email nonlin-users-request@cs.umd.edu for more info)
;;;; 
;;;; Code to load nonlin.
;;;;
;;;; Author: B. Kettler

(in-package :common-lisp-user)

;;;; *** NOTE: Change the following 2 parameters for your installation.

(defvar *nonlin-dir* "your-nonlin-dir/"
  "nonlin directory - a string ending in a / or whatever the valid directory delimeter is on your system")

(defvar *nonlin-binary-file-type*   "fasl"
  "file extension for compiled lisp files")

;;;;

(defparameter *nonlin-files*
  '("nonlin-package" 
    "util" "def" "dev" "unify" "macros" "readschema" "tome" "gost" "schema"
    "link" "plan" "expand" "establish" "init-planner" ; "init-always"
    "mark" "printplan" "backtrack")
  "file names of Nonlin files"
)

(defun load-nonlin-sources ()
  "Load Nonlin Source Files"
  (format t "~&Loading Nonlin Source Files into Package :nonlin...")
  (dolist (file *nonlin-files*)
     (load (concatenate 'string *nonlin-dir* file ".lisp")))
  (use-package :nonlin)
)
(defun load-l () (load-nonlin-sources)) ; for backwards compatibility


(defun compile-nonlin-sources ()
  "Compile Nonlin Source Files"
  (format t "~&Loading Nonlin Source Files into Package :nonlin...")
  (proclaim '(optimize (safety 2)))
  (dolist (file *nonlin-files*)
     (compile-file (concatenate 'string *nonlin-dir* file)))
  (use-package :nonlin)
)
(defun compile-l () (compile-nonlin-sources))


(defun load-nonlin-binaries ()
   "Load Nonlin Object Files"
   (format t "~&Loading Nonlin Binary Files into Package :nonlin...")
   (dolist (file *nonlin-files*)
     (load (concatenate 'string *nonlin-dir* file)))
   (use-package :nonlin)
)
(defun load-o () (load-nonlin-binaries))

;;;;

(progn
(format t "~% UM Nonlin Implementation V1.2")
(format t "~% (c) 1992")
(format t "~% Department of Computer Science")
(format t "~% University of Maryland at College Park")
(format t "~% -----------------------------------------")
(format t "~%    To load sources: (load-nonlin-sources)")
(format t "~% To compile sources: (compile-nonlin-sources)")
(format t "~%   To load binaries: (load-nonlin-binaries)")
(terpri)
(format t "~% Remember to load your operators file.")
(format t "~% Invoke (plan-for ...) to run planner.")
(format t "~% See the User Manual for more details.")
(format t "~% -----------------------------------------")
'ok
)

(when (string= *nonlin-dir* "your-nonlin-dir/")
   (format t "~&~%*** Warning: you must set the parameter *nonlin-dir* in load-nonlin.lisp"))

