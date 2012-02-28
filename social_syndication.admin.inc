<?php
/**
 * @file
 * Admin page callback for the social_syndication module.
 */

/**
 * Builds and returns the twitter_syndication settings form.
 */
function social_syndication_admin_profile_form($form, &$form_state) {
  $form = array();

  $form['site_profiles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Wide Media Profiles'),
    '#collapsible' => FALSE,
  );

  $form['site_profiles']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter username'),
    '#default_value' => 'metaltoadtest' //TODO make this a variable after checking if set
    '#size' => 40,
    'maxlength' =>  16,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save'
  );

  return $form;
}