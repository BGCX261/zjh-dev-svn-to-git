<?php 
 // Connects to your Database 
 mysql_connect("localhost", "root", "1111") or die(mysql_error()); 
 mysql_select_db("drupal") or die(mysql_error()); 
 $data = mysql_query("SELECT * FROM node") or die(mysql_error()); 
 Print "<table border cellpadding=3>";
 while($info = mysql_fetch_array( $data )) 
 { 
 Print "<tr>"; 
 Print "<th>nid:</th> <td>".$info['nid'] . "</td> "; 
 Print "<th>vid:</th> <td>".$info['vid'] . "</td> "; 
 Print "<th>type:</th> <td>".$info['type'] . "</td> "; 
 Print "<th>title:</th> <td>".$info['title'] . " </td></tr>"; 
 } 
 Print "</table>"; 
 ?>
