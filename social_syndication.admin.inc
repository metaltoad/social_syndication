<?php
/**
 * @file
 * Admin page callback for the social_syndication module.
 */

/**
 * Builds and returns the twitter_syndication settings form.
 */
function social_syndication_admin_profile_form($form, &$form_state) {
  $form['site_profiles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Media Profiles'),
    '#collapsible' => FALSE,
  );

  $form['site_profiles']['ss_twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter username'),
    '#default_value' => variable_get('ss_twitter', ''),
    '#size' => 40,
    '#maxlength' =>  16,
  );
  $form['site_profiles']['ss_twitter_hashtags'] = array(
    '#type' => 'textfield',
    '#title' => t('Automatically #Hashtag these words in a post title'),
    '#description' => t('If there are words you would like to be converted to hashtags when they appear in a post title, list them here as comma separated values'),
    '#default_value' => variable_get('ss_twitter_hashtags', ''),
    '#size' => 80,
    '#maxlength' => 100,
  );
  $form['site_profiles']['ss_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node types'),
    '#description' => t('Choose which post types you would like to enable for social media posting'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('ss_node_types', array('story' => 'story', 'blog' => 'blog')),
  );
  $form['site_profiles']['ss_taxonomy_hashtags'] = array(
    '#type' => 'checkbox',
    '#title' => t('Taxonomy Hashtags'),
    '#default_value' => variable_get('ss_taxonomy_hashtags', 0),
    '#description' => t('Check if you want to add hashtags from a taxonomy field on your nodes'),
    '#options' => array('Use taxonomy terms as Twitter hashtags'),
  );
  $form['site_profiles']['ss_taxonomy_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Taxonomy Name'),
    '#description' => t('Enter the name of your Twitter taxonomy vocabulary'),
    '#default_value' => variable_get('ss_taxonomy_name', ''),
    '#size' => 40,
    '#maxlength' => 100,
    '#weight' => 20,
    '#states' => array(
      'visible' => array(
        ':input[name="ss_taxonomy_hashtags"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return system_settings_form($form);
}

/**
 * Menu callback - admin form for Oauth Twitter settings.
 */
function twitter_admin_profile_form($form, &$form_state) {
  $form['setup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Setup a Twitter account'),
    '#description' => t('Submitting this form will redirect you to Twitter where you can login with the account that you would like to use to promote your content'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Authorize'),
  );
  return system_settings_form($form);
}

/*
 * Submit handler. Steps through the OAuth process for Twitter.
 */
function twitter_admin_profile_form_submit($form, &$form_state) {
  $url = 'http://api.twitter.com/1/statuses/update.json';
$params = array(
  'status' => 'hello world',
);

$consumer = new OAuthConsumer('Tp2ne3J67mIatPw4gVTRg', 'RmZ1y64J2dhysssO7PCeebDpaLQGuZfmv90kbwZzY');
$token = new OAuthToken('221541626-fiLCTkYUg5Lwz4l7O5O86I04iqKXUe8z0Gzmmk2Y', 'FlJ2z3RSATBTmVtSOjMpQq3m4W9KOdlUoav2q1oxOI');
$request = OAuthRequest::from_consumer_and_token($consumer, $token, 'POST', $url, $params);
$request->sign_request(new OAuthSignatureMethod_HMAC_SHA1(), $consumer, $token);
$params = $request->get_parameters();
$response = drupal_http_request($request->get_normalized_http_url(), array(), 'POST', $request->get_parameters());
dpm($response);
}

/**
 * Menu callback - admin form for Oauth Bitly settings.
 */
function bitly_admin_profile_form($form, &$form_state) {
  $form['setup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Connect to Bitly'),
    '#description' => t('If you would like to use your Bitly account to shorten URLs for Twitter, enter your username and API key here.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['setup']['ss_bitly_login'] = array(
    '#type' => 'textfield',
    '#title' => t('Bit.ly username'),
    '#default_value' => variable_get('ss_bitly_login', ''),
    '#size' => 40,
    '#maxlength' =>  100,
  );
  $form['setup']['ss_bitly_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Bit.ly API Key'),
    '#description' => t('To find your API key, login to your bit.ly account and go to the settings page.'),
    '#default_value' => variable_get('ss_bitly_key', ''),
  );
  return system_settings_form($form);
}

