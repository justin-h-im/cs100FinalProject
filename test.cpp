#include "include/ui.h"
#include "gtest/gtest.h"

// Expect true when the first input is 1.
TEST(UISuite, startMenuInput1) {
  ui *testUI = new ui();
  EXPECT_TRUE(testUI->outputStartMenu());
}

// Expect false when the first input is 3.
TEST(UISuite, startMenuInput3) {
  ui *testUI = new ui();
  EXPECT_FALSE(testUI->outputStartMenu());
}

// Expect true after inputting values that exist on the board.
TEST(UISuite, turnMenu) {
    ui *testUI = new ui();
    EXPECT_NO_THROW(testUI->outputTurnMenu());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}