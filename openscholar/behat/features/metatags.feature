Feature:
  Testing the metatags.

  @api
  Scenario: Testing default metatags.
    Given I visit "john/about"
     Then I should see the meta tag "description" with value "Page about john"

  @api
  Scenario: Testing custom metatags.
    Given I am logging in as "john"
      And I edit the page meta data of "about" in "john"
      And I fill in "Summary description" with "custom tag value"
      And I press "Save"
     Then I visit "john/about"
      And I should see the meta tag "description" with value "custom tag value"

  @api
  Scenario: Edit meta description tag on vsite (group) bundles.
    Given I am logging in as "john"
      And I visit "john/cp/settings"
      And I fill in "Meta description" with "A site about John"
      And I press "Save"
      And I clear the cache
     When I visit "john"
     Then I should see the meta tag "description" with value "A site about John"
     Then I visit "john/cp/settings"
      And I fill in "Meta description" with "New value"
      And I press "Save"
      And I clear the cache
     When I visit "john"
     Then I should see the meta tag "description" with value "New value"
