echo "Enter the number to check if it is Prime or Not"
read num
i=2
flag=0
while [ $i -lt $num ]
do
    if [ $(($num % $i)) -eq 0 ]
    then
        flag=1
        break
    fi
    i=$(($i+1))
done
if [ $flag -eq 1 ]
then
    echo "$num is not a Prime Number"
else
    echo "$num is a Prime Number"
fi