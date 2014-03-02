Feature: testing the more like this block.

  @api
  Scenario: Testing the block when searching content related by title
    Given the widget "More like this" is set in the "Blog" page
     When I visit "john/blog/first-blog"
     Then I should see "Second blog"

  @api @current
  Scenario: Testing the block when searching content related by content
    Given the widget "More like this" is set in the "Blog" page with the following <settings>:
      | Title                                                             | uncheck | checkbox    |
      | The full content of the posts(body)                               | check   | checkbox    |
      | Taxonomy names                                                    | uncheck | checkbox    |
      | Related posts must be of the same type as the post being viewed.  | uncheck | checkbox    |
      | Node type                                                         | All     | select list |
     When I visit "john/blog/first-blog"
     Then I should see "JFK lorem"

  @api
  Scenario: Testing the block when searching content related by taxonomy names
