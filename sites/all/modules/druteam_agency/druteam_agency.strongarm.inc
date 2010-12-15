<?php

/**
 * Implementation of hook_strongarm().
 */
function druteam_agency_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'anonymous';
  $strongarm->value = 'Visitor';
  $export['anonymous'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache';
  $strongarm->value = 1;
  $export['cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_lifetime';
  $strongarm->value = '0';
  $export['cache_lifetime'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_add_captcha_description';
  $strongarm->value = 0;
  $export['captcha_add_captcha_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_administration_mode';
  $strongarm->value = 0;
  $export['captcha_administration_mode'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_allow_on_admin_pages';
  $strongarm->value = 0;
  $export['captcha_allow_on_admin_pages'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_challenge';
  $strongarm->value = 'image_captcha/Image';
  $export['captcha_default_challenge'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_default_validation';
  $strongarm->value = '1';
  $export['captcha_default_validation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_description';
  $strongarm->value = 'This question is for testing whether you are a human visitor and to prevent automated spam submissions.';
  $export['captcha_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_log_wrong_responses';
  $strongarm->value = 1;
  $export['captcha_log_wrong_responses'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_persistence';
  $strongarm->value = '3';
  $export['captcha_persistence'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_placement_map_cache';
  $strongarm->value = array(
    'comment_form' => array(
      'path' => array(),
      'key' => NULL,
      'weight' => 18.9,
    ),
    'user_login_block' => array(
      'path' => array(
        0 => 'actions',
      ),
      'key' => 'submit',
      'weight' => NULL,
    ),
  );
  $export['captcha_placement_map_cache'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'captcha_response';
  $strongarm->value = '9338';
  $export['captcha_response'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = TRUE;
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_application';
  $strongarm->value = 0;
  $export['comment_anonymous_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_application';
  $strongarm->value = '2';
  $export['comment_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_application';
  $strongarm->value = 0;
  $export['comment_default_mode_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_application';
  $strongarm->value = '300';
  $export['comment_default_per_page_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_application';
  $strongarm->value = 1;
  $export['comment_form_location_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_application';
  $strongarm->value = '0';
  $export['comment_preview_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_application';
  $strongarm->value = 0;
  $export['comment_subject_field_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_css_cache_files';
  $strongarm->value = array(
    '0d5fe121dd8bc9b9f78f756f0fcaae57160c7e079cf43aaa2c846c0d08edf772' => 'public://css/css_cleuHFojkzTyTanalmqhTbYgaYI8S0j6iuAiZoZvOAM.css',
    'bf92e31c60fa07eb7da65f83171fc20740ddf18087bea00483d659047e51e383' => 'public://css/css_jmllDc5tlxGbCKh4jlYdH4w68El6_8mFEneJ4NbrQCg.css',
    'ed0be830835b691e397a4b30f659fe3047feaeeb8248b0e6bb65c27f5f435b81' => 'public://css/css_u4tZmVaEJg19yUZuOd4F7yG9sr0j9KsNqnjl7hxa62E.css',
    '4dea61ef09b94564f59beb7afdb98d5e12e9229499f98c9dcadd81e46362bc9e' => 'public://css/css_lGvHcBz2tCRpfuVj6GXqI1l65OjlfxKO76xwYBEgMLw.css',
    '343cc0352026f342f48b133af2804c0fa359705d7246aa5da49eb6f0941b677c' => 'public://css/css_y5wAtrgVdv1NPN7j3qoVfK2HjS-wwves0Ix1RptAIKU.css',
    '6c5223ff9aa42dc4df9b9e5e2248e4bd1445dd273859c6f8195a8ceb338c55a2' => 'public://css/css_2THG1eGiBIizsWFeexsNe1iDifJ00QRS9uSd03rY9co.css',
    '7ce09372c89263b94c4557fc4a2f7f451caead7f64171e7f053799c2ed0bf633' => 'public://css/css_gl9X6aap5syCavkrYHV3Z4qfLbp07N0zmPlW_dUVhMA.css',
    'd05b4da5d8fbb3b977b57055d875ecd6415c72310903b67f8beca9c5f839f66c' => 'public://css/css_OsoGjp1rFKElSNeE5wwP_v_ecdjnuiiOH-fVcgel3Lo.css',
    '95ab5c656cb70ce95c599c4d555b5d133094e018cc2a8ef085c59db25f46dbb6' => 'public://css/css_-P2rIOA1q2ZzUZfcYv2C2YmquGHtWRaujC-EKd7D1VI.css',
  );
  $export['drupal_css_cache_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_js_cache_files';
  $strongarm->value = array(
    '1b462addd35f1ca5372768244565381204b27215aef0ebafa30963a4fd5fb9f7' => 'public://js/js_VF53tELsw3kPql1FJD633rc2wNa0fCZV5Foz0aUfhvo.js',
    '0aa37227ca6df9b70d855fa50b646002ad8ade618fc5fbbfacd0ef0153764a8f' => 'public://js/js_dzfLoPp7wVCLCjNuhecxFU36AXGek8gtTZxLVCOe9iA.js',
    '777f6de16b94ab5487997e953b356b5df39d4ce7977e93ef7f4a02b86d467569' => 'public://js/js_OS34NE8-Q22NdSfXRFQWt1gfEqoecT5C0J86rZUs3zA.js',
    '303194cbf2f9827bd19c4a5c5a9b28bf0f8787a9652d25ee04345215a6506e9c' => 'public://js/js_eIAhklcOBGlZqIiVf8Fgy8nrQwFLvB1DHZfTV4C9Yek.js',
    '71b8fed99623bc0e085e4e0ad8a2bed01762b5cb59b4258199ae6490ebd24af7' => 'public://js/js__naawDmwOGzsfve_MA6Mg7U9e9SJl14lZii5kPXRLX8.js',
    'de0e5f61e6e3e185dd7e0e1c04317dfccf636bb214f105f6bfa05397a734a55a' => 'public://js/js_fLdHE6DXyKqTo0SbNtZ_V6DKbTgnkIdszhaGUgqVtLI.js',
    '117a8c2efc73136c1fb909b16a929eac89052ebc2878c285bfecc5a3e51ac538' => 'public://js/js_dzfLoPp7wVCLCjNuhecxFU36AXGek8gtTZxLVCOe9iA.js',
    '0e0226c617c2c9b37935c924ec46555b941343ab6dc6ef96bab195219441d426' => 'public://js/js_s5JqgM7YjjWelZ-WRvELBQ56EMcYIurptqicvQX5AJ4.js',
    '569a67ee1e44d77769aab733ae01785ce2eac8598efa6288339015d5abea0171' => 'public://js/js_pulghhrYNiB9z-rDYWy1wwKbhCLampSOOsV4LyGAxUc.js',
    'cc290719c5058036888e592a171d776f0c5288487251b60e35835770abe663e8' => 'public://js/js_7cJ6L3JjgrbWfYlVxLcNqg_E9iduW9uMSo5hlYR40jw.js',
    '409c63eb524f8f5cdf1b19e94332eeae7b4cc53541b04adf4f99d821f220ae37' => 'public://js/js_uD4PBBsvMy4kzs3KA53IgnP536-XwTlUl2FFiI7aUFA.js',
    'fdfa40c3f3edac2b7eb5a987ddb8ff6be3e01e04889dc36f6a4d42b40b5d4bee' => 'public://js/js_LjMDhLq29QTlA7m98ql_kP_LgT8pk_SjpKm70cu7cME.js',
    '73673ccd977fd8b08a0ea53ec69c5f7991c161b667b80ea9b25d75211f996f22' => 'public://js/js_xQakYN1JdEe2CVqj3lwGPtFTa7lWeqakpJ85uyNlf0c.js',
    '4cd6c1ed158b9dba83b26909360d80ad2b232e518a83376fb3afe495dd07dedc' => 'public://js/js_-HuxYXEJIGaWZETeouk9cSeax0ZocNXqTZo3iL_mfgQ.js',
    'e045597f2af003bab0291eb974e1c7873823676902fef67e87633a9cc48fd042' => 'public://js/js_dzfLoPp7wVCLCjNuhecxFU36AXGek8gtTZxLVCOe9iA.js',
    'e12cc3c00c3c0d057d86d24c3acc63073dde39c7846e1194b8b58396d2250df0' => 'public://js/js_eXjhnbnRslQB0N7cwVbDJZvep_ijlUSkeo0V50fyAgc.js',
  );
  $export['drupal_js_cache_files'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_profiles';
  $strongarm->value = array(
    1 => array(
      'name' => 'User-1',
      'usertab' => 1,
      'filesize' => 0,
      'quota' => 0,
      'tuquota' => 0,
      'extensions' => '*',
      'dimensions' => '1200x1200',
      'filenum' => 0,
      'directories' => array(
        0 => array(
          'name' => '.',
          'subnav' => 1,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 1,
          'resize' => 1,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Small',
          'dimensions' => '90x90',
          'prefix' => 'small_',
          'suffix' => '',
        ),
        1 => array(
          'name' => 'Medium',
          'dimensions' => '120x120',
          'prefix' => 'medium_',
          'suffix' => '',
        ),
        2 => array(
          'name' => 'Large',
          'dimensions' => '180x180',
          'prefix' => 'large_',
          'suffix' => '',
        ),
      ),
    ),
    2 => array(
      'name' => 'Sample profile',
      'usertab' => 1,
      'filesize' => 1,
      'quota' => 2,
      'tuquota' => 0,
      'extensions' => 'gif png jpg jpeg',
      'dimensions' => '800x600',
      'filenum' => 1,
      'directories' => array(
        0 => array(
          'name' => 'u%uid',
          'subnav' => 0,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 0,
          'resize' => 0,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Thumb',
          'dimensions' => '90x90',
          'prefix' => 'thumb_',
          'suffix' => '',
        ),
      ),
    ),
  );
  $export['imce_profiles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_application';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_application'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 1;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '1';
  $export['user_register'] = $strongarm;

  return $export;
}
