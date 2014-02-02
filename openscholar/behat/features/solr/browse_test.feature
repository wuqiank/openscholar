Feature:
  Testing browse function using apache solr.

  @api @momo
  Scenario: Test basic people browse with apache solr
    Given I visit "john/browse/people"
     Then I should see "filter by taxonomy"
      And I should see "browse person"
      And I should see "Norma"
     Then I click "Air"
      And I should not see "Norma"

  @api @momo
  Scenario: Test browse with one term not showing categories block
    Given I visit "john/browse/bios"
     Then I should not see "filter by taxonomy"
      And I should see "browse bio"
      And I should see "John doe biography"

  @api @momo
  Scenario: Test direct browsing of category
    Given I visit "john/browse/gallery/?f[0]=sm_og_vocabulary%3Ataxonomy_term%3A3"
     Then I should see "filter by taxonomy"
      And I should see "browse media gallery"
      And I should not see "John doe biography"
      And I should see "Kittens gallery"
