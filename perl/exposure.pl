#!/usr/bin/env perl

sub hello
{
	print "Hello World!";
}
sub ary3and5
{
	$count =0;
	$num = 1;
	@nums;
	while($count < 100)
	{
		if((($num%3)*($num%5))==0)
		{
			push(@nums,$num);
			$count++;
		}
		$num++;
	}
	return @nums;
}

sub is_anagram
{
	@first = sort split("",$_[0]);
	@second = sort split("",$_[1]);
	return 0 if(scalar(@first)!=scalar(@second));
	
	for($i=0;$i<scalar(@first);$i++)
	{
		return 0 if($first[$i] ne $second[$i]);
	}
	return 1;
}

sub remove
{
	$buff = $_[0];
	$buff =~ s/$_[1]//g;
	return $buff;
}

sub sum
{
	$total = 0;
	foreach $num (@_)
	{
		$total += $num;
	}
	return $total;
}

sub bsort
{
	@ary = @_;
	for($i=0;$i<scalar(@ary);$i++)
	{
		$delta = -1;
		while(($ary[$i+$delta+1]< $ary[$i+$delta]) && ($i+$delta >= 0))
		{
			$buff = $ary[$i+$delta+1];
			$ary[$i+$delta+1]= $ary[$i+$delta];
			$ary[$i+$delta] = $buff;
			$delta--;
		}
	}
	return @ary;
}

foreach $num (ary3and5()){
	print $num . "\n";
}
print is_anagram("testing","gnistte") . "\n";
print remove("hello","l") . "\n";
print sum(ary3and5()) . "\n";
foreach $num (bsort((5,4,3,6,2))){
	print $num . "\n";
}
