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
      And I fill in "Description" with "custom tag value"
      And I press "Save"
     Then I visit "john/about"
      And I should see the meta tag "description" with value "custom tag value"
