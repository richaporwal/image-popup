(function($) {
    Drupal.behaviors.mymodule = {
        attach: function(context, settings) {  
            $(window).load( function() {
            $('.img-pop').smoothZoom({
            	// Options go here
            });
        });
}


    };

}(jQuery));