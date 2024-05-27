#include <gtest/gtest.h>

TEST(SampleTest1, AssertionTrue) {
    EXPECT_TRUE(2 > 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
