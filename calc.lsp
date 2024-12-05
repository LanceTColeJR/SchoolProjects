;;Lance Cole
;;11-29-2024
;;Project 3

;;coeff function
(defun coeff(t)
(cond
  (car t)) )

;;degree function
(defun degree(t)
  (cond
    (cadr t)) )

;;negTerm function
(defun negTerm(t)
  (cond
    (list ( -(coeff t)) (degree t))) )

;;compareTerms function
(defun compareTerms(t1 t2)
  (> (degree t1) (degree t2)))

;;add terms
(defun addTerms (t1 t2)
  (cond
    (if (=(degree t1) (degree t2))
	(list (+ (coeff t1) (coeff t2)) (degree t1))
	(list t1 t2)))

;;mulTerms
  (defun mulTerms (t1 t2)
    (list (* (coeff t1) (coeff t2)) (+ (degree t1) (degree t2)))

;;normalize
(defun normalize (poly)
  (cond
    (if (null poly) '()
	(let ((sorted (sort poly #'compareTerms)))
	  ))) )
;;negPoly
(defun negPoly (p)
  (cond
    (if (null p) '()
	(cons (negTerm (car p)) (negPoly)))))
;;addPolys
(defun addPolys (p1 p2)
  (if (null p2)
      (normalize p1)
      (addPolys (insertT (car p2) p1) (cdr p2))))

;;InsertTerm function

