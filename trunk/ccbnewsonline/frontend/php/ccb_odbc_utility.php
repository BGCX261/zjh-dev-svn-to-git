<?php

// Create an array list from $result containing all array objects
function ccb_odbc_utility_fetch_array($result)
{
	$finalArray;
	$ti = 0;
	$temp;
	while(1)
	{
		$temp = odbc_fetch_array($result);
		if($temp == false)
			break;
		$finalArray[$ti] = $temp;
		$ti = $ti + 1;
	}
	return $finalArray;
}

?>
