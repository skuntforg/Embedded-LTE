<?php
    $servername = "localhost";
    $username = "root";
    $password = "rootpassword";
    $dbName = "arduino";
    //establishing the connection to the db.
    $conn = mysqli_connect($servername, $username, $password);
    $db = mysqli_select_db ($conn, $dbName);

// Check connection
if ($conn -> connect_errno) {
  echo "Failed to connect to MySQL: " . $conn -> connect_error;
  exit();
}
    

 