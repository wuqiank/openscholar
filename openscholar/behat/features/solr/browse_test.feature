Feature:
  Testing browse function using apache solr.

  @api
  Scenario: Test basic people browse with apache solr
    Given I visit "john/browse/person"
     Then I should see "filter by taxonomy"
      And I should see "browse person"
      And I should see "Norma"
     Then I click "Air"
      And I should not see "Norma"
