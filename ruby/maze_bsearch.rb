#!/usr/bin/env ruby
point = Struct.new(:x,:y,:prev) do
	def ==(other)
		x==other.x && y==other.y
	end
end
ary = IO.readlines("maze.in")
length,width = ary.shift.split.map{|s| s.to_i}
map =[]
pieces = {"#"=>1,"*"=>2," "=>0,"S"=>3,"E"=>4};
length.times {map << ary.shift.chomp.each_char.map{|s| pieces[s]};}
position = point.new(0,0,nil)
target = point.new(0,0,nil)
row = map.detect{|aa| aa.include?(3)}
position.x = row.index(3)
position.y = map.index(row)
row = map.detect{|aa| aa.include?(4)}
target.x = row.index(4);
target.y = map.index(row);
queue = []
queue << position
visited = []
while(queue.size > 0) do
	curr = queue.shift
	(-1..1).each do |dx|
		(-1..1).each do |dy|
			next if dx==dy || dx*dy!=0
			turn = point.new(curr.x+dx,curr.y+dy,curr)
			if map[turn.y][turn.x]!=1&&!visited.include?(turn) then
				queue << turn
			end
		end
	end
	visited << curr
	if curr == target then
		until curr.prev.nil? do
			map[curr.y][curr.x] = 2
			curr = curr.prev
		end
	end
end

map.each do |row|
	puts row.map{|p| pieces.invert[p]}.join
end
