<?php

function number2roman($num, $isUpper=true)
{
    $n = intval($num);
    $res = '';

    /*** roman_numerals array ***/
    $roman_numerals = [
        'M' => 1000,
        'CM' => 900,
        'D' => 500,
        'CD' => 400,
        'C' => 100,
        'XC' => 90,
        'L' => 50,
        'XL' => 40,
        'X' => 10,
        'IX' => 9,
        'V' => 5,
        'IV' => 4,
        'I' => 1
    ];

    foreach ($roman_numerals as $roman => $number) {
        /*** divide to get matches ***/
        $matches = intval($n / $number);

        /*** assign the roman char * $matches ***/
        $res .= str_repeat($roman, $matches);

        /*** substract from the number ***/
        $n = $n % $number;
    }

    /*** return the res ***/
    if ($isUpper) {
        return $res;
    } else {
        return strtolower($res);
    }
}
