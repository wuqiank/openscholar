Feature:
  Testing the managing of OpenScholar

  @api
  Scenario: Check that all of the apps are turned on
    Given I am logging in as "john"
      And I visit "john"
     When I click "Build"
      #And I should see "Apps"
     Then I should see the "spaces" table with the following <contents>:
      | Bio/CV        | Public |
      | Blog          | Public |
      | Booklets      | Public |
      | Classes       | Public |
      | Dataverse     | Public |
      | Events        | Public |
      | Image Gallery | Public |
      | Links         | Public |
      | News          | Public |
      | Basic Pages   | Public |
      | Presentations | Public |
      | Profiles      | Public |
      | Publications  | Public |
      | Reader        | Public |
      | Software      | Public |

    @api
    Scenario: Check site owner can't manage permissions of disabled app.
      Given I am logging in as "john"
        And I visit "john"
        And I click "Build"
        And I select "Disabled" from "edit-spaces-features-os-booklets"
        And I press "Save configuration"
       When I visit "john/cp/users/permissions"
       Then I should not see "Create book page content"
        And I should see "Create Bio content"

    @api
    Scenario: Check enabling app brings back its permissions.
      Given I am logging in as "john"
        And I visit "john"
        And I click "Build"
        And I select "Public" from "edit-spaces-features-os-booklets"
        And I press "Save configuration"
       When I visit "john/cp/users/permissions"
       Then I should see "Create book page content"
