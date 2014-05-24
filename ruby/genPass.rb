#!/usr/bin/env ruby

pass = [rand(9)]
6.times do
	allowed = (1..9).to_a - [pass, (pass.last+1)].flatten
	buff = allowed[rand(allowed.size)]
	pass << buff
end
puts pass.join
