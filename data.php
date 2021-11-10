<?php
include ('connecttoserver.php');
$sql_insert = "INSERT INTO testingturnips (temperature, humidity) VALUES ('".$_GET['temperature']."', '".$_GET['humidity']."')";
if(mysqli_query($conn,$sql_insert))
{
echo "Done";
mysqli_close($conn);
}
else
{
echo "error is ".mysqli_error($conn);
}
?> 