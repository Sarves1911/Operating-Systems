echo  "Enter Two Numbers"
read a b
echo "Enter Your Choice"
echo "1. Addition"
echo "2.Substraction"
echo "3.Multiplication"
echo "4.Division"
echo "5.Modulus"
read ch

case $ch in
1)res=$(($a+$b))
;;
2)res=$(($a -$b))
;;
3)res=$(($a * $b))
;;
4)res=$(($a / $b))
;;
5)res=$(($a % $b))
esac

echo "Result : $res "

