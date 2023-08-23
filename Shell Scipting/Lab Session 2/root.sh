#roots of quadratic equation
echo "Enter the coefficients of the quadratic equation"
read a b c
d=$(($b*$b-4*$a*$c))
if [ $d -lt 0 ]
then
    echo "Roots are imaginary"
elif [ $d -eq 0 ]
then
    echo "Roots are real and equal"
    root=$(echo "scale=2;-$b/(2*$a)" | bc)
    echo "Root is $root"
else
    echo "Roots are real and unequal"
    root1=$(echo "scale=2;(-$b+sqrt($d))/(2*$a)" | bc - l)
    root2=$(echo "scale=2;(-$b-sqrt($d))/(2*$a)" | bc - l)
    echo "Roots are $root1 and $root2"
fi