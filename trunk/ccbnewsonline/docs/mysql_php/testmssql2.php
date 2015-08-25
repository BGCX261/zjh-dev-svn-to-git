<?php
// Connects to your Database
mssql_connect("localhost\MSSQLSERVER2008", "mssqladmin", "1234") or die("Failed to connect to MS SQL"); 
mssql_select_db("drupal") or die("Failed to select DB"); 
$data = mssql_query("SELECT * FROM node") or die("Failed to query"); 
Print "<table border cellpadding=3>";
while($info = mssql_fetch_array( $data )) 
{ 
 Print "<tr>";
 Print "<th>nid:</th> <td>".$info['nid'] . "</td> "; 
 Print "<th>vid:</th> <td>".$info['vid'] . "</td> "; 
 Print "<th>type:</th> <td>".$info['type'] . "</td> "; 
 Print "<th>title:</th> <td>".$info['title'] . " </td></tr>"; 
} 
Print "</table>"; 
?>
