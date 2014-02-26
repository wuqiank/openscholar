Feature:
  Testing the pinserver.

  @api
  Scenario: Verify the page /user/login changes when pinserver is enabled.
    Given I am not logged in
     When I enable pinserver
      And I visit "user/login"
      And I should see "Login via Harvard University ID (HUID)."
     Then I disable pinserver
      And I visit "user/login"
      And I should not see "Login via Harvard University ID (HUID)."
