echo "Enter the number of Elements"
read n
temp=$n
sum=0
avg=0
while [ $temp -gt 0 ]
do  
    read num
    sum=$(($sum+$num))
    temp=$(($temp-1))
done
avg=$(($sum/$n))
echo "The Sum of the Numbers is $sum"
echo "The Average of the Numbers is $avg"