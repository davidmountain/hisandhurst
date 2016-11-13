<?php
    $calling_file = basename($_SERVER['REQUEST_URI'], "");
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">

   <?php
   if (!isset($keywords)) $keywords = "art, reduce, reuse recycle, Hurstpierpoint";
   if (!isset($depth)) $depth=0;

   if ($depth==-1) {
     // -1 signifies unknown depth, so we go absolute to the root of the site instead
     $dotdots = "/";
   } else {
     // set the ../../../ string used as a prefix for all paths. (or "" for the default 0 depth)
     $dotdots = str_repeat("../" , $depth);
   }

   $full_title = "His&amp;Hurst";
   if (isset($title)) {
      $full_title .= " - ";
      $full_title .= $title;
   }
?>

<meta content="<?=$keywords?>" name="keywords" />
<title><?=$full_title ?></title>

<link rel="shortcut icon" href="<?=$dotdots ?>img/favico.ico" type="image/ico" />
<link rel="stylesheet" href="<?=$dotdots ?>css/bootstrap.css">
<link rel="stylesheet" href="<?=$dotdots ?>css/hurst.css" type="text/css" media="screen" />

<script src="<?=$dotdots ?>js/hurst.js"></script>
<script src="<?=$dotdots ?>js/jquery-1.7.2.min.js"></script>
<script src="<?=$dotdots ?>js/jquery.smooth-scroll.min.js"></script>


<script>
  jQuery(document).ready(function($) {
      $('a').smoothScroll({
        speed: 1000,
        easing: 'easeInOutCubic'
      });

      $('.showOlderChanges').on('click', function(e){
        $('.changelog .old').slideDown('slow');
        $(this).fadeOut();
        e.preventDefault();
      })
  });
</script>

<!-- UNCOMMENT ME! -->
<!--script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-19734728-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
	ga.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'stats.g.doubleclick.net/dc.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script-->

</head>
<body>

<script src="<?=$dotdots ?>js/bootstrap.min.js"></script>

<!-- TODO set menu active -->
<!--standard header start -->
    <nav class="navbar navbar-inverse navbar-fixed-top">
        <div class="container">
            <div style="height:120px"></div>

            <div id="navbar" class="collapse navbar-collapse">
                <!--img border="10" src="<?=$dotdots ?>img/long-banner.jpeg"-->
            <!-- TODO nmessy messy tidy up this php -->
            <ul class="nav navbar-nav">
<?php
$header = new Header();
$header->print_nav_link($calling_file, 'about.php', 'About', $dotdots);
$header->print_nav_link($calling_file, 'gallery.php', 'Gallery', $dotdots);
$header->print_nav_link($calling_file, 'contact.php', 'Contact', $dotdots);
?>
            </ul>
        </div>
            </div>
    </nav>
<!--standard header end -->

<div class="container">

<?php
class Header
{
    // get a navbar link, highlighted if calling file is this link
    public function print_nav_link($calling_file, $link_file, $link_title, $dotdots ) {
        $link_div = '<li';
        if ($calling_file == $link_file) {
            $link_div .= " class=\"active\"";
        }
        $link_div .='><a href="'.$link_file.'">'.$link_title.'</a></li>';
        print $link_div;
    }
}
?>

