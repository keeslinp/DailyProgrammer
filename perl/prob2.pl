#!/usr/bin/env perl

$last = 0;
$curr = 1;
$sum = 0;
while($curr <= 4000000)
{
	$curr += $last;
	$last = $curr - $last;
	$sum += $curr if $curr % 2 ==0;
}
print $sum . "\n";

