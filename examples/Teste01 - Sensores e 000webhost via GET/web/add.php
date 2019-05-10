<?php

	include("conn.php");
    
	$link=Connection();

	$oxigDiss = $_GET["do"];
	$condElet = $_GET["ec"];
	$potOxiRed = $_GET["orp"];
	$ph = $_GET["ph"];
	$temper = $_GET["temp"];

	echo "[DEBUG] Dado do sensor de DO: " . $oxigDiss . "\n";
	echo "[DEBUG] Dado do sensor de EC: " . $condElet . "\n";
	echo "[DEBUG] Dado do sensor de ORP: " . $potOxiRed . "\n";
	echo "[DEBUG] Dado do sensor de ph: " . $ph . "\n";
	echo "[DEBUG] Dado do sensor de Temperatura: " . $temper . "\n";

	$query = "INSERT INTO `id9383262_projcamarao`.`TANQUE_001`
			(`DO`,`EC`,`ORP`,`PH`,`TEMPERATURA`) VALUES
			($oxigDiss,$condElet,$potOxiRed,$ph,$temper)";
   
	mysql_query($query,$link);
	mysql_close($link);

	echo "[DEBUG] Novos dados dos sensores adicionados com sucesso!\n";

?>