#! /usr/bin/ruby
starts = ['FOR','IF']
ends = ['NEXT','ENDIF']
tabIndex = 0
out = ""
count = gets.chomp.to_i
tab = gets.chomp
count.times do
  line = gets.delete("·").delete("»")
  command = line.split[0]
  tabIndex+= (starts.include?(command) ? 1 : 0) + (ends.include?(command) ? -1 : 0)
  out += tab*tabIndex + line
end
puts out
