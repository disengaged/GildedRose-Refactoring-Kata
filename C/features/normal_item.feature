Feature: Normal Item
  As a shop owner
  In order to sell a Normal Item
  I need to determine the quality given the time left until its sell by date

  Scenario: Item has ten days left to the sell by date
    Given the quality is 15 and days til best by is 20
    When 2 days have passed
    Then the quality should be 13
    And the days left until best by should be 18
