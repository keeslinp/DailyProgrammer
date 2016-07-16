#!/usr/bin/env ruby
out = []
while (input=gets.chomp)!="" do
  val,conversion = input[0..-3].to_f,input[-2,2]
  case conversion
  when /[rd]{2}/
    out << (val * (Math::PI/180)**(conversion[0]=='d'?1:-1)).to_i.to_s  + conversion[1]
  when /[kfc]{2}/
    val = (val-32) * 5/9 if (conversion[0] == 'f')
    val -= 273 if (conversion[0] == 'k')
    val = val * 9/5 + 32 if(conversion[1] == 'f')
    val += 273 if (conversion[1]=='k')
    out << val.to_i.to_s + conversion[1]
  else
    out << "No candidate for conversion"
  end
end
puts out
