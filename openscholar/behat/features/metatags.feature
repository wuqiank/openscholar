Feature:
  Testing the metatags.

  @api
  Scenario: Testing default metatags.
    Given I visit "john/about"
     Then I should see the meta tag "description" with value "Page about john"

  @api
  Scenario: Edit meta description on a taxonomy term.
    Given I am logging in as "john"
    And I create the term "Has description" in vocabulary "science"
    Then I edit the term "Has description"
    And I fill in "Description" with "This term has a meta description."
    Then I press "Save"
    When I visit the original page for the term "Has description"
    Then I should see the meta tag "description" with value "This term has a meta description."

  @api
  Scenario: Testing custom metatags.
    Given I am logging in as "john"
      And I edit the page meta data of "about" in "john"
      And I fill in "Summary description" with "custom tag value"
      And I press "Save"
     Then I visit "john/about"
      And I should see the meta tag "description" with value "custom tag value"
