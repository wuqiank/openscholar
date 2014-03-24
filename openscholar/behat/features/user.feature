Feature: User functionality testing.

  @api
  Scenario: Verify that user pages are inaccessible to anonymous users.
    Given I am not logged in
     Then I should be redirected in the following <cases>:
  #  | Request                    | Response Code | Final URL   |
     | users/admin                | 403           | users/admin |

  @api
  Scenario: User pages are accessible to the logging in user.
    Given I am logging in as "john"
     When I visit "/user"
     Then I should see "View"
      And I should see "Edit"

  @api
  Scenario: Adding a user to a vsite.
    Given I am logging in as "john"
     When I visit "john/cp/users/add"
      And I fill in "User" with "michelle"
      And I press "Add users"
     Then I should see "michelle has been added to the group John."

  @api
  Scenario: Enable custom roles and permissions in a VSite.
    Given I am logging in as "john"
      And I visit "john/cp/users/permissions"
     When I click "Edit roles and permissions"
      And I press "Confirm"
      And I visit "john/cp/users/permissions"
     Then I should see the button "Save permissions"

  @api
  Scenario: Create a custom role in a vsite.
    Given I am logging in as "john"
     When I visit "john/cp/users/roles"
      And I fill in "Name" with "New Custom Role"
      And I press "Add role"
      And I visit "john/cp/users/roles"
     Then I should see "New Custom Role"
      And I give the role "New Custom Role" in the group "john" the permission "Create Blog entry content"

  @api
  Scenario: Assign a custom role to a vsite member.
    Given I am logging in as "john"
     When I give the user "klark" the role "New Custom Role" in the group "john"
     Then I should verify that the user "klark" has a role of "New Custom Role" in the group "john"

  @api
  Scenario: Test node creation permissions of a custom role - check failure.
    Given I am logging in as "klark"
     When I go to "john/node/add/book"
     Then I should get a "403" HTTP response

  @api
  Scenario: Test node creation permissions of a custom role - check success.
    Given I am logging in as "klark"
     When I go to "john/node/add/blog"
     Then I should get a "200" HTTP response

  @api
  Scenario: Create a custom role in a vsite with edit & administer widgets
            permissions.
    Given I am logging in as "john"
      And I visit "john/cp/users/roles"
      And I fill in "Name" with "Widget editor"
      And I press "Add role"
      And I visit "john/cp/users/roles"
      And I give the role "Widget editor" in the group "john" the permission "Administer widgets"
      And I give the role "Widget editor" in the group "john" the permission "Edit widgets"
      And I give the user "michelle" the role "Widget editor" in the group "john"
      And I am logging in as "michelle"
      And I visit "john/publications"
      And I should see the text "Edit Widget" under "contextual-links-wrapper"
      And I should see the text "Remove Widget" under "contextual-links-wrapper"
          # Check "edit" ability.
     When I visit "john/os/widget/boxes/os_publications_recent/edit?destination=publications"
     Then I should get a "200" HTTP response

  @api
  Scenario: Test that a user with a custom role that doesn't have content
            creation Permissions won't have the "content" link in the cp for
            adding content.
    Given I am logging in as "michelle"
     When I visit "john"
     Then I should not see the text "Content" under "toolbar"

  @api
  Scenario: Restore default roles and permissions in a VSite.
    Given I am logging in as "john"
      And I visit "john/cp/users/roles"
     When I click "Restore default roles and permissions"
      And I press "Confirm"
      And I visit "john/cp/users/roles"
     Then I should not see the button "Save permissions"
