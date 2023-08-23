#to find sum of prime numbers up till n
echo "Enter the number"
read num
sum=0
for (( i=2; i<=$num; i++ ))
do
    flag=0
    for (( j=2; j<=$(($i/2)); j++ ))
    do
        if [ $(($i%$j)) -eq 0 ]
        then
            flag=1
            break
        fi
    done
    if [ $flag -eq 0 ]
    then
        sum=$(($sum+$i))
    fi
done
echo "Sum of prime numbers is $sum"
