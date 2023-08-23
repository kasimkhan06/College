choice=1
while [ $choice -ne -1 ]
do 
    echo "Enter Two Numbers"
    read a 
    read b
    ans=0
    echo -e "Menu\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n-1 - Exit\n"
    read choice
    case "$choice" in 
        1) ans=$(($a+$b))
        ;;
        2) ans=$(($a-$b))
        ;;
        3) ans=$(($a*$b))
        ;;
        4) ans=$(($a/$b))
        ;;
        -1) echo "Exit Success"
        ;;
    esac
    echo "The Result After The Operation is : $ans"
done