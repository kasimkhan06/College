echo "Enter the Number of Terms in Fibonacci Series"
read n
t1=0
t2=1
echo "The Fibonacci Series is:"
while [ $n -gt 0 ]
do
    echo "$t1"
    temp=$(($t1+$t2))
    t1=$t2
    t2=$temp
    n=$(($n-1))
done