<?php

function roman2number($roman)
{
    $conv = [
        ["letter" => 'I', "number" => 1],
        ["letter" => 'V', "number" => 5],
        ["letter" => 'X', "number" => 10],
        ["letter" => 'L', "number" => 50],
        ["letter" => 'C', "number" => 100],
        ["letter" => 'D', "number" => 500],
        ["letter" => 'M', "number" => 1000],
        ["letter" => 0, "number" => 0]
    ];
    $arabic = 0;
    $state = 0;
    $sidx = 0;
    $len = strlen($roman);

    while ($len >= 0) {
        $i = 0;
        $sidx = $len;

        while ($conv[$i]['number'] > 0) {
            if (strtoupper(@$roman[$sidx]) == $conv[$i]['letter']) {
                if ($state > $conv[$i]['number']) {
                    $arabic -= $conv[$i]['number'];
                } else {
                    $arabic += $conv[$i]['number'];
                    $state = $conv[$i]['number'];
                }
            }
            $i++;
        }

        $len--;
    }

    return($arabic);
}
