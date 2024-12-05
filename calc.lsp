;;Lance Cole
;;11-29-2024
;;Project 3

;;coeff function, which should take a single term as parameter.
;;This function should return the coeﬃ-cient of the term.
(defun coeff(t)
(cond
  (car t)) )

;;degree function, which should take a single term as parameter.
;;This function should return the degree
of the term
(defun degree(t)
  (cond
    (cadr t)) )

;;negTerm function, which should take a single term as its only parameter.
;;This function should return a term with the same degree as the parameter and the negation of the corresponding coeﬃcient.
(defun negTerm(t)
  (cond
    (list ( -(coeff t)) (degree t))) )

;;compareTerms function, which should take two parameters, both of which will be terms. This function should return true if the first term’s degree is larger than the second and false (nil) otherwise.
(defun compareTerms(t1 t2)
  (> (degree t1) (degree t2)))

;;add terms,
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
(defun insertTerm (term poly)
  (if (null poly)
      (list term)
      (let ((head (car poly)))
        (cond
         ((> (degree term) (degree head)) (cons term poly))
         ((= (degree term) (degree head))
          (let ((new-coeff (+ (coeff term) (coeff head))))
            (if (/= new-coeff 0)
                (cons (list new-coeff (degree head)) (cdr poly))
                (cdr poly))))
         (t (cons head (insertTerm term (cdr poly))))))))

;;subPolys subtract
(defun subPolys (p1 p2)
  (addPolys p1 (negPoly p2)))
  
;;multiply
(defun mulPolys (p1 p2)
  (mulPolys-helper p1 p2 '()))

;;helper function that accumulates the result polynomial recursively
(defun mulPolys-helper (p1 p2 result)
  (if (null p1)
      (normalize result)
      (mulPolys-helper
       (cdr p1)
       p2
       (addPolys result (mulPoly-helper (car p1) p2)))))

;;returns the new list
(defun mulPoly-helper (term poly)
  (if (null poly)
      '()
      (cons (mulTerms term (car poly))
            (mulPoly-helper term (cdr poly)))))
            
;;evalPoly: Evaluate a polynomial at a given value
(defun evalPoly (poly x)
  (if (null poly)
      0
      (+ (* (coeff (car poly))
            (expt x (degree (car poly))))
         (evalPoly (cdr poly) x))))
