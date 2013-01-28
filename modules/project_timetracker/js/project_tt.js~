/*
 * @file
 * JavaScript for ajax_example.
 *
 * See @link ajax_example_dependent_dropdown_degrades @endlink for
 * details on what this file does. It is not used in any other example.
 */

(function($) {

  // Re-enable form elements that are disabled for non-ajax situations.
  Drupal.behaviors.projectTt = {
    attach: function() {
      //Submit Button
      function pushBackMessage( data ) {
        console.log(data);
        $('input[name=tt_submit]').removeAttr('disabled').attr('value', 'Ready for more...');
      }
      jQuery('input[name=tt_submit]').click(
        function(event) {
          event.preventDefault();
          $(this).attr('disabled', 'disabled').attr('value', 'Thinking...');
          var formData = jQuery('.project-tt-form form').serialize();
          //submit time to the system
          $.ajax(
            {
              type: "POST",
              url: 'http://local.d8.com/system/timetracker/v1/addtime',
              data: formData,
              success: pushBackMessage
            }
          );
        }
      );
    }
  };

})(jQuery);
