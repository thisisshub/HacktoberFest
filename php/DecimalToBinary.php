<?php

function binary($decimal) {
    $left;
    $result;

    if ($decimal <= 1) {
        echo (int)$decimal;
        return;
    }

    $left = $decimal % 2;
    $result = $decimal / 2;
    binary($result);
    echo (int)$left;
}

binary(50);
?>
