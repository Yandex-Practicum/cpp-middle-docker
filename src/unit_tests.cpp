#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BasicCheck, SimpleCheck) { EXPECT_EQ(1 + 1, 2); }
