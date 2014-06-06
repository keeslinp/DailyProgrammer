#!/usr/bin/env lisp
(print (- (expt (apply '+ (loop for x from 1 to 100 collect x)) 2) (apply '+ (loop for x from 1 to 100 collect (expt x 2)))))
