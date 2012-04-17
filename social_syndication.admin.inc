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
  $form['site_profiles']['ss_tweet_format'] = array(
    '#type' => 'textfield',
    '#title' => t('Set the default format of your tweets'),
    '#description' => t('If you have the Token module enabled, you maybe use Token references to set sensible defaults for outgoing tweets. Each message is totally customizable in the node edit form as well.'),
    '#default_value' => variable_get('ss_tweet_format', 'New post: [node:title] [node:url] (@[node:author:ss_twitter_username])'),
    '#size' => 80,
    '#maxlength' => 100,
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
    '#description' => t("If you don't already have one, create an app for the Twitter account you want to use to broadcast your content at ") . l('dev.twitter.com', 'https://dev.twitter.com/apps/new') . t(' then enter your credentials here.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['setup']['ss_twitter_oauthconsumerkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Consumer Key'),
    '#default_value' => variable_get('ss_twitter_oauthconsumerkey', ''),
    '#size' => 40,
    '#maxlength' =>  100,
  );
  $form['setup']['ss_twitter_oauthconsumersecret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Consumer Secret '),
    '#default_value' => variable_get('ss_twitter_oauthconsumersecret', ''),
    '#size' => 40,
    '#maxlength' =>  100,
  );
  $form['setup']['ss_twitter_oauthaccesstoken'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Access Token'),
    '#default_value' => variable_get('ss_twitter_oauthaccesstoken', ''),
    '#size' => 40,
    '#maxlength' =>  100,
  );
  $form['setup']['ss_twitter_oauthaccesstokensecret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Access Token Secret'),
    '#default_value' => variable_get('ss_twitter_oauthaccesstokensecret', ''),
    '#size' => 40,
    '#maxlength' =>  100,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return system_settings_form($form);
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

