Feature:
  Testing the os_profiles app settings.

  @api
  Scenario: Test that changing the display type affects the "/people" path,
            with display type "title".
    Given I am logging in as "john"
     When I set the variable "views_og_cache_invalidate_node" to "1"
      And I go to the "os_profiles" app settings in the vsite "john"
      And I select the radio button named "os_profiles_display_type" with value "title"
      And I press "Save configuration"
      And I visit "john/people"
      And I invalidate cache
     Then I should not see "Drupal developer at Gizra.inc"

  @api
  Scenario: Test that changing the display type affects the "/people" path,
            With display type "sidebar_teaser".
    Given I am logging in as "john"
     When I go to the "os_profiles" app settings in the vsite "john"
      And I select the radio button named "os_profiles_display_type" with value "sidebar_teaser"
      And I press "Save configuration"
      And I visit "john/people"
      And I invalidate cache
     Then I should see "Actress"
      And I should not see "AKA Marilyn Monroe"

  @api
  Scenario: Test that changing the display type affects the people term pages,
            for example: "john/people/science/air".
    Given I am logging in as "john"
     When I go to the "os_profiles" app settings in the vsite "john"
      And I select the radio button named "os_profiles_display_type" with value "title"
      And I press "Save configuration"
      And I visit "john/people/science/wind"
      And I invalidate cache
     Then I should not see "Drupal developer at Gizra.inc"

