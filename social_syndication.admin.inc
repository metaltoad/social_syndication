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
 * Builds and returns the Twitter oauth form.
 */
function twitter_admin_profile_form($form, &$form_state) {
  $form['twitter_profile'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authorize a Twitter account'),
    '#collapsible' => FALSE,
  );

  $form['twitter_profile']['twitter'] = array(
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

