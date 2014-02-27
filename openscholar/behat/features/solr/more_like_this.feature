Feature: testing the more like this block.

  @api
  Scenario: Testing the block when searching content related by title
    Given the widget "More like this" is set in the "Blog" page
     When I visit "john/blog/first-blog"
     Then I should see "Second blog"

  @api
  Scenario: Testing the block when searching content related by content

  @api
  Scenario: Testing the block when searching content related by taxonomy names
