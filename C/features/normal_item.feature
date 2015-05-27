Feature: Normal Item
  As a shop owner
  In order to sell a Normal Item
  I need to determine the quality given the time left until its sell by date

  Scenario: Item has ten days left to the sell by date
    Given the quality is 15
    When days have passed
    Then the quality should be 13
