#!/usr/bin/env ruby
def fib(n)
	    (1.61803398875**n-(-1.61803398875)**(n*-1))/(5**(0.5))
end

puts fib(ARGV[0].to_i);
