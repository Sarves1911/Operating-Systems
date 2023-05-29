hello() {
    a=0
    b=5

    while [ $a -lt $b ]
    do 
        echo "Hello World !"
        a=$(( a + 1 ))
    done
}

hello
echo "Sarvesh Koli"