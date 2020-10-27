<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Vehicle condition report</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
	<h1>Vehicle condition report</h1>
	<?php if($_POST['practice']): ?>
		<h2>Pratica Numero <?= $_POST['practice'] ?> </h2>
	<?php endif; ?>

	<?php
		var_dump($_POST);
	?>
	
	<?php include 'aa.svg' ?>

	<ul class='custom-menu'>
		<li data-action="rotto">Rotto</li>
		<li data-action="ammaccato">Ammaccato</li>
		<li data-action="rigato">Rigato</li>
		<li data-action="mancante">Mancante</li>
		<li data-action="niente">Niente</li>
	</ul>

	<form id="form" action="" method="post">
		<h3>^^^^ DATI REPORT inseriti ^^^^</h3>
		<?php 
			if($_POST["damage_report"]): 
				foreach($_POST["damage_report"] as $damage_type=>$damaged_parts):
					foreach($damaged_parts as $damaged_part):
		?>
			<input name="damage_report[<?=$damage_type?>][]" value="<?=$damaged_part?>" />
		<?php
					endforeach;
				endforeach;
			endif;
		?>
		<h3>^^^^ DATI REPORT DA $POST ^^^^</h3>
		<input type="submit" value="SALVA">
	</form>

	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
	<script src="car.js"></script>
</body>

</html>