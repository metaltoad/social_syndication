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

  $form['site_profiles']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter username'),
    '#default_value' => 'metaltoadtest', //TODO make this a variable after checking if set
    '#size' => 40,
    '#maxlength' =>  16,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Menu callback - admin form of Oauth Twitter settings.
 */
function twitter_admin_profile_form($form, &$form_state) {
  $form['setup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Setup a Twitter account'),
    '#description' => t('Submitting this form will redirect you to Twitter where you can login with the account that you would like to use to promote your content'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['setup']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter username'),
    '#default_value' => '', //TODO make this a variable after checking if set
    '#size' => 40,
    '#maxlength' =>  100,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Authorize'),
  );
  return $form;
}

/*
 * Submit handler. Steps through the OAuth process.
 */
function twitter_admin_profile_form_submit($form, &$form_state) {
  
}

