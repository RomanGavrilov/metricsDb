#include <gtest/gtest.h>

TEST(SampleTest2, AssertionFalse) {
    EXPECT_FALSE(false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
