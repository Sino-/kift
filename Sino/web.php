<!DOCTYPE html>
 
<head>
 	<img background="background.jpg">
	<title>K.I.F.T. U.I.</title>
 
	<!-- JavaScript -->
	<script type="text/javascript">
		// Put code here or set the src attribute
	</script>
 
	<!-- CSS -->
	<style type="text/css"> 
		body { background-image: url("background.jpg"); background-size: cover; margin: 0; padding: 0; font-family: sans-serif; font-size: 20px; }
		p { margin-bottom: 10px; }
		.butn {font-weight: bold; font-size: 20px}

	</style>
 
</head>
 
<body>
 <div>
	<a href="?who=true"><button class="butn">Who is connected?</button></a>
	<a href="?where=true"><button class="butn">Where are you connected?</button></a>
 	<a href="?time=true"><button class="butn">What time is it?</button></a>
 	<a href="?joke=true"><button class="butn">Tell me a joke.</button></a>
 	<a href="?coin=true"><button class="butn">Flip a coin.</button></a>
 	<a href="?dice=true"><button class="butn">Roll the dice.</button></a>
 	<a href="?email=true"><button class="butn">Send an email.</button></a>
 	<div id="light-control">
	 	<a href="?lightup=true"><button class="butn">Turn the lights up.</button></a>
	 	<a href="?lightdown=true"><button class="butn">Turn the lights down.</button></a>
	 	<a href="?lighton=true"><button class="butn">Turn the lights on.</button></a>
	 	<a href="?lightoff=true"><button class="butn">Turn the lights off.</button></a>
	 </div>
</div>
<script type="text/javascript">
	var H = document.getElementById("hours").value;

</script>
<?php
if ($_GET['time']) {
	$STR="\"WHAT TIME IS IT\"";
  shell_exec("./kift $STR");
}
if ($_GET['joke']) {
	$STR="\"TELL ME A JOKE\"";
  shell_exec("./kift $STR");
}
if ($_GET['time']) {
	$STR="\"WHAT TIME IS IT\"";
  shell_exec("./kift $STR");
}
if ($_GET['lightup']) {
	$STR="\"TURN THE LIGHTS UP\"";
  shell_exec("./kift $STR");
}
if ($_GET['lightdown']) {
	$STR="\"TURN THE LIGHTS DOWN\"";
  shell_exec("./kift $STR");
}
if ($_GET['lighton']) {
	$STR="\"TURN THE LIGHTS ON\"";
  shell_exec("./kift $STR");
}
if ($_GET['lightoff']) {
	$STR="\"TURN THE LIGHTS OFF\"";
  shell_exec("./kift $STR");
}
if ($_GET['who']) {
	$STR="\"WHO IS CONNECTED\"";
  shell_exec("./kift $STR");
}
if ($_GET['coin']) {
	$STR="\"FLIP A COIN\"";
  shell_exec("./kift $STR");
}
if ($_GET['dice']) {
	$STR="\"ROLL THE DICE\"";
  shell_exec("./kift $STR");
}
if ($_GET['email']) {
	$STR="\"SEND AN EMAIL\"";
  shell_exec("./kift $STR");
}
if ($_GET['where']) {
	$STR="\"WHERE ARE THEY CONNECTED\"";
  shell_exec("./kift $STR");
}
?>
 
</body>
 
</html>