(function ($) {

/**
 * Settings for tweeting new node content
 */
Drupal.behaviors.social_syndicationFieldsetSummaries = {
  attach: function (context) {
    // Use the fieldset class to identify the vertical tab element
    $('fieldset#edit-social-syndication', context).drupalSetSummary(function (context) {
      // Depending on the checkbox status, the settings will be customized, so
      // update the summary with the custom setting textfield string or a use a
      // default string.
      if ($('#edit-social-syndication-enabled', context).attr('checked')) {
        return Drupal.t('Custom social settings');
      }
      else {
        return Drupal.t('Using default');
      }
    });
  }
};

})(jQuery);