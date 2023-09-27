#to display 20 leap years from the year 2000
base=2000
for (( i=0; i<20; i++ ))
do
    echo $(($base+($i*4)))
done