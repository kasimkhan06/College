echo "Enter the number"
read num
#to find sum o fcubes of digits
sum=0
while [ $num -gt 0 ]
do
    rem=$(($num%10))
    sum=$(($sum+($rem*$rem*$rem)))
    num=$(($num/10))
done
echo "Sum of cubes of digits is $sum"
