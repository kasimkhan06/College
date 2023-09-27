echo Enter the coefficient of x^2:
read a
echo Enter the coefficient of x:
read b
echo Enter the constant term:
read c

if [ $a -ne 0 ]
then
    d=$(($(($b*$b))-$((4*$a*$c))))   
    b2=$((-$b))
    a2=$((2*$a))
    if [ $d -lt 0 ]
    then
        x=`echo "-($d)" | bc`
        sq=`echo "scale=2; sqrt ( $x )" | bc`
        echo "Root 1= ($b2 + $sq i) / $a2"
        echo "Root 2= ($b2 - $sq i) / $a2"
        
    elif [ $d -eq 0 ]
    then
        res=$(( $b2 / $a2))
        echo "Root = $res"
    else
        sq=`echo "scale=2; sqrt( $d )" | bc`
        res1=`echo "scale=2; ( $b2 + $sq) / ( $a2 )"|bc`
        res2=`echo "scale=2; ( $b2 - $sq) / ( $a2 )"|bc`
        echo "Root 1= $res1"
        echo "Root 2= $res2"
    fi
else
    echo "Coefficient of x^2 can not be 0"
fi