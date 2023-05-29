echo PRAJWAL KORADDE
echo "Enter a number"
#Read the number
read num
fact=1
for((i=1;i<num;i++))
{
fact=$((fact*i))
}
echo "the factorial of $num is :"
echo $fact
