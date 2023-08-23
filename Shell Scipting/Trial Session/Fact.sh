echo "Enter Number to Find Factorial"
read num
fact=1
while [ $num -gt 0 ]
do  
    fact=$(($fact*$num))
    num=$(($num-1))
done
echo "The Factorial of the Number is $fact"