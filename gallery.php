<?php
include './lib/header.php.inc'
?>

<script type="text/javascript">
function slideSwitch() {
    var $active = $('#slideshow IMG.active');
    if ( $active.length == 0 ) $active = $('#slideshow IMG:last');
    var $next =  $active.next().length ? $active.next()
        : $('#slideshow IMG:first');
    $active.addClass('last-active');

    $next.css({opacity: 0.0})
        .addClass('active')
        .animate({opacity: 1.0}, 1000, function() {
            $active.removeClass('active last-active');
        });
}

$(function() {
    setInterval( "slideSwitch()", 3000 );
});

</script>

<style type="text/css">

/*** set the width and height to match your images **/

#slideshow {
    position:relative;
    height:400px;
}

#slideshow IMG {
    position:absolute;
    top:0;
    left:0;
    z-index:8;
    opacity:0.0;
}

#slideshow IMG.active {
    z-index:10;
    opacity:1.0;
}

#slideshow IMG.last-active {
    z-index:9;
}

</style>

<div class="col-md-8 lead">

<div id="slideshow">
    <img src="gallery/a.jpeg" alt="Slideshow Image 1" class="active" />
    <img src="gallery/b.jpeg" alt="Slideshow Image 1"/>
    <img src="gallery/c.jpeg" alt="Slideshow Image 1"/>
    <img src="gallery/d.jpeg" alt="Slideshow Image 1"/>
    <img src="gallery/e.jpeg" alt="Slideshow Image 1"/>
</div>

<?php
include './lib/footer.php.inc'
?>




