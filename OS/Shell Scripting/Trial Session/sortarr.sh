my_arr=(10 9 8 7 6 5 4 3 2 1)

for ((i=0; i<10; i++))
do
    for ((j=0; j<10-i-1; j++))
    do
        if [ ${my_arr[j]} -gt ${my_arr[j+1]} ]
        then
            temp=${my_arr[j]}
            my_arr[$j]=${my_arr[$((j+1))]}
            my_arr[$((j+1))]=$temp
        fi
    done
done

echo "Sorted array: ${my_arr[@]}"