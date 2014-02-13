Feature:
  Testing sticky profiles.

  @api
  Scenario: Verify that the a sticky profile is sticky in both the LOP widget
            and in the "/people" page.
    Given I am logging in as "john"
      And the widget "List of posts" is set in the "People" page with the following <settings>:
          | description  | people lop   | textfield    |
          | title        | People       | textfield    |
          | content_type | Person       | select list  |
          | display      | Teaser       | select list  |
          | sort_by      | Alphabetical | select list  |
      And I make the node "Norma Jeane Mortenson" sticky
     When I visit "john/people"
     Then I should see the profile "Norma Jeane Mortenson" comes before "John Fitzgerald Kennedy"
      And I should see the profile "Norma Jeane Mortenson" comes before "John Fitzgerald Kennedy" in the LOP widget
