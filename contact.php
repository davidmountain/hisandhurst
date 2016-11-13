<?php
include './lib/header.php.inc'
?>

<div class="col-md-8 lead">
  <form method="post" action="lib/sendmail.php">
    Email: <input name="email" type="text" /><br />
    Message:<br />
    <textarea name="message" rows="15" cols="60">
    </textarea><br />
    <input type="submit"/>
  </form>
</div>


<?php
include './lib/footer.php.inc'
?>
