/**
 *  @file
 *  README for the Social Syndication Module.
 */

-- SUMMARY --

Social Syndication is* a suite of modules that allow you to automatically post your Drupal content to Twitter and will add Facebook and Google Plus in the near future.

-- REQUIREMENTS --

  Oauth module: http://drupal.org/project/oauth
  You will need to create an 'app' for Oauth authorization at http://dev.twitter.com

-- OPTIONAL HELPER MODULES --

  Shorten Module: http://drupal.org/project/shorten

-- INSTALLATION --

  Download the Social Syndication module and place the unzipped folder into /sites/all/modules/ or /sites/all/modules/contrib

  Enable Social Syndication and Twitter syndication

  Enable permissions at /admin/people/permissions
    Post Content to Social Media
    Send Content to Twitter

-- CONFIGURATION --

  Create a Twitter app at http://dev.twitter.com and enter the required Oauth tokens at admin/config/services/social_syndication/twitter

  If you want to connect a Bitly account, you may enter your account name and API key at admin/config/services/social_syndication/bitly

  If you want to be able to include the Twitter handle of the currently logged-in user with a Token, you can add their Twitter handle in the User edit form (admin/people).

  Configure posting options at admin/config/services/social_syndication
    Twitter username: the account which content to which content will be posted

    Title Hashtags: If there are words you want to always be turned into hashtags if they appear in a title, add them as a comma separated list

    Node types: Choose which node types to enable for

    Default Tweet Format: The tweet form makes use of Tokens if you have the Token module enabled. You can set the default format of your tweets in this field. Tweets are completely customizable at the time of posting.

    Taxonomy Hashtags: If you want to use a particular taxonomy vocabulary as hashtags in your tweets, you can create the field in the relevant content types and then fill in the machine name of the field here.

-- POSTING -- 

  For enabled content types, look for the Social Syndication tab on the node edit form. You may choose to post tweets on edited nodes as well as new ones (though Twitter will not let you post the exact same tweet more than once).

  You will get a sucess message with a copy of your tweet, or an error message with the reason for the error and a link to the edit form so you can retry if necessary.
