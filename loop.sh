echo "Name: Sarvesh Koli"
echo "Enter a number"
read n1
i=1
while [ $i -le 10 ]
do
    echo "$n1 x $i = $(( n1*i ))"
    i=$(( i + 1 ))
done
