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
    '#default_value' => variable_get('ss_twitter', ''), //TODO make this a variable after checking if set
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
    '#description' => t('Choose which post types you would like to enable social posting'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('ss_node_types', array('story' => 'story', 'blog' => 'blog')),
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
  $url = 'https://api.twitter.com/oauth/request_token';
  $params = array(
    'oauth_callback' => url('admin/services/social_syndication/twitter', array('absolute' => TRUE)),
  );
  $consumer = new OAuthConsumer('Tp2ne3J67mIatPw4gVTRg', 'RmZ1y64J2dhysssO7PCeebDpaLQGuZfmv90kbwZzY', $params['oauth_callback']);
  $token = new OAuthToken(NULL, NULL);
  $request = OAuthRequest::from_consumer_and_token($consumer, $token, 'POST', $url, $params);
  $request->sign_request(new OAuthSignatureMethod_HMAC_SHA1(), $consumer, $token);
  $params = $request->get_parameters();
  unset($params['oauth_request_token']);
  $response = drupal_http_request($request->get_normalized_http_url(), array(), 'POST', $request->get_parameters());
  dpm($response);
  //dpm($_SERVER, 'Server');
  dpm(array($request->get_normalized_http_url(), $request->get_parameters()));
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

