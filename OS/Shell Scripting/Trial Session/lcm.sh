#lcm
read a
read b

if [ $a -gt $b ]
then
    max=$a
else
    max=$b
fi

while [ 1 ]
do
    if [[ $(($max%$a)) -eq 0 && $(($max%$b)) -eq 0 ]]
    then
        echo "LCM is $max"
        break
    fi
    max=$(($max+1))
done
