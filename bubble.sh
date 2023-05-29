echo PRAJWAL KORADE
echo "Enter size of array";
read  n; #get the size of array from user.
echo "Enter the array";
read -a arr;  #get the array form user eg: 2 3 4 5 6
echo "Orignal array is: ${arr[*]}"; #print orignal array
flag=1;
for (( i = 0; i < $n-1; i++ ))
do
    flag=0;
    for ((j = 0; j < $n-1-$i; j++ ))
    do
        if [[ ${arr[$j]} -gt ${arr[$j+1]} ]]
        then
            temp=${arr[$j]};
            arr[$j]=${arr[$j+1]};
            arr[$j+1]=$temp;
            flag=1;
        fi
    done
    if [[ $flag -eq 0 ]]; then
        break;
    fi
  done
echo "Final sorted Array is ${arr[*]}";

