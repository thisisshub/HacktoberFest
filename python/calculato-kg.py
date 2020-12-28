<?php
//JOAO FERREIRA
$s=$_GET["s"];
$h=$_GET["a"];

	if($s == "feminino" || $s == "f"){
		$cl= (62.1 * $h) - 44.7;
			echo number_format($cl, 2);
	}
		else if($s == "masculino" || $s == "m"){
			$cl = (72.7 * $h) - 58;
				echo number_format($cl, 2);
		}
			else{
				echo "sexo indefinido";
			}
?>
