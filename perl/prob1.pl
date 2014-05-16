#!/usr/bin/env perl
$sum = 0;
for $i (1..999)
{
	if($i%3 * $i%5 ==0)
	{
		$sum+=$i;
	}
}
print "$sum\n";
