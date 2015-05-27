#include <gilded_rose.h>

#include <csteps.h>
#include <assertion-macros/assertion-macros.h>

#include <stdio.h>

#define STEP_PREFIX gilded_rose_steps

static Item items[1];

void before_scenario() {
  // make sure that failed assertions are aborted
  __assert_bail = 1;

  init_item(&items[0], "+5 Dexterity Vest", 10, 20);
}

WHEN("^(\d+) days have passed$") (int days) {
  for (; days > 0; days--) {
    update_quality(items, 1);
  }
}

GIVEN("^the quality is (\d+) and days til best by is (\d+)$") (int quality, int days) {
  items[0].quality = quality;
  items[0].sell_in = days;
}

THEN("^the quality should be (\d+)$") (int quality) {
  assert_equal(items[0].quality, quality);
}

THEN("^the days left until best by should be (\d+)$") (int days) {
  assert_equal(items[0].sell_in, days);
}
