#include "include/ui.h"
#include "gtest/gtest.h"

TEST(UISuite, turnMenu) {
    ui *testUI = new ui();
    EXPECT_NO_THROW(testUI->outputTurnMenu());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}