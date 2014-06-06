#!/usr/bin/env clisp
(print (apply '+ (loop for x from 1 to 999
	     collect (if (= 0 (* (mod x 5) (mod x 3))) x 0))))
