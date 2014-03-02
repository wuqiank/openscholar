Feature: testing the more like this block.

  @api
  Scenario: Testing the block when searching content related by title.
    Given the widget "More like this" is set in the "Blog" page
     When I visit "john/blog/first-blog"
     Then I should see "Second blog"

  @api
  Scenario: Testing the block when searching content related by content
    Given I am logging in as "john"
     When the widget "More like this" is set in the "Blog" page with the following <settings>:
       # For some reason Behat can't find the check box of the title with the
       # name title. Using the label of the check instead.
       | mlt_fl[label]                                                     | uncheck | checkbox    |
       | The full content of the posts(body)                               | check   | checkbox    |
       | Taxonomy names                                                    | uncheck | checkbox    |
       | Related posts must be of the same type as the post being viewed.  | uncheck | checkbox    |
       | Node type                                                         | All     | select list |
     When I visit "john/blog/first-blog"
     Then I should see "JFK lorem"

  @api
  Scenario: Testing the block when searching content related by taxonomy names.
    Given I am logging in as "john"
     When the widget "More like this" is set in the "Classes" page with the following <settings>:
       | mlt_fl[label]                                                     | uncheck | checkbox    |
       | The full content of the posts(body)                               | uncheck | checkbox    |
       | Taxonomy names                                                    | check   | checkbox    |
       | Related posts must be of the same type as the post being viewed.  | check   | checkbox    |
     When I visit "john/classes/john-f-kennedy"
     Then I should see "Neil Armstrong"
