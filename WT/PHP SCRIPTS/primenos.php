<?php
function print_primes() {
    $num = 15;
    echo "Prime numbers between 1 to $num is: ";
    for ($j = 2; $j <= $num; $j++) {
        $flag = 1;
        for ($i = 2; $i * $i <= $j; $i++) {
            if ($j % $i == 0) {
                $flag = 0;
                break;
            }
        }
        if ($flag == 1) {
            echo $j . " ";
        }
    }
    echo "\n";
}

print_primes();
?>