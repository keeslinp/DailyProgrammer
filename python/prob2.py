num1 =0;
num2=1;
total =0;
while(num2 < 4000000):
	num2+= num1;
	num1 = num2-num1;
	if num2 %2 ==0: total+=num2
print(total)

