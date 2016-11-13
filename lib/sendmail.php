<?php
  $email = $_REQUEST['email'] ;
  $message = $_REQUEST['message'] ;

  mail( "hisandhurst@gmail.com", "Feedback Form Results",
    $message, "From: $email" );
  header( "Location: ../contactresponse.php" );
?>