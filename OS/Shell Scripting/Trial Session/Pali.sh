echo "Enter the Number To check If Palindrome or Not!"
read n
orig=$n
rev=0
while [ $n -gt 0 ]
do
    rem=$(($n%10))
    rev=$(($rev*10+$rem))
    n=$(($n/10))
done
echo "$rev"
if [ $orig -eq $rev ]
then    
    echo "Number is Palindrome!"
else    
    echo "Number is Not Palindrome!"
fi