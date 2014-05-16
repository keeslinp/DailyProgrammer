#!/usr/bin/env ruby

def qsort(ary)
	return ary if ary.size <=1
	compare = ary.shift
	less = ary.select{|i| i<compare}
	more = ary - less
	less = qsort(less)
	more = qsort(more)
#	p less + [compare] + ary
	return less + [compare] + more
end

p qsort(ARGV.map{|s| s.to_i})
