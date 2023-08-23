echo "Enter a number"
read num
if [ $(($num % 2)) -eq 0 ]
then echo " The Entered Number is Even!"
else echo "The Entered Number is Odd!"
fi