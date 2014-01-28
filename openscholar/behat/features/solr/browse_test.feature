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

  @api
  Scenario: Test browse with one term not showing categories block
    Given I visit "john/browse/bio"
     Then I should not see "filter by taxonomy"
      And I should see "browse bio"
      And I should see "John doe biography"

  @api
  Scenario: Test direct browsing of category
    Given I visit "john/browse/media_gallery/?f[0]=sm_og_vocabulary%3Ataxonomy_term%3A3"
     Then I should see "filter by taxonomy"
      And I should see "browse media gallery"
      And I should not see "John doe biography"
      And I should see "Kittens gallery"
