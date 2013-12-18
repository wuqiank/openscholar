Feature: Testing the publications part in the site.

  @api
  Scenario: Testing a user can publish biblio entries.
    Given I am logging in as "john"
     When I visit "john/node/add/biblio"
      And I select "Book" from "Publication Type"
      And I press "Next"
      And I fill in "Title" with "The Secret Garden"
      And I fill in "biblio_year" with "1911"
     When I press "Save"
     Then I should see "The Secret Garden"
