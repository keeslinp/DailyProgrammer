#!/usr/bin/env ruby
ary = ARGV.map{|s| s.to_i}
sorted = []
while ary.size > 0 do
	ary.each_index do |i|
		item= ary[i];
		j = i
		parent = (j-1)/2;
		while ary[parent] > item && j>0 do
			ary[j] = ary[parent]
			j = parent
			parent = (j-1)/2
		end
		ary[j] = item
	end
	sorted << ary.shift
end
p sorted
