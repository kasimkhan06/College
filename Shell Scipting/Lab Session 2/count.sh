#to count odd and even digits of a number
echo "Enter the number"
read num
even=0
odd=0
while [ $num -gt 0 ]
do
    rem=$(($num%10))
    if [ $(($rem%2)) -eq 0 ]
    then
        even=$(($even+1))
    else
        odd=$(($odd+1))
    fi
    num=$(($num/10))
done
echo "Number of even digits is $even"
echo "Number of odd digits is $odd"