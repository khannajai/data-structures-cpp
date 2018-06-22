#include "gtest/gtest.h"
#include "fraction.h"

using namespace std;

TEST(testFraction, testNumerator)
{
    fraction one("1/1");
    EXPECT_EQ(1, one.getNumerator());
}

GTEST_API_ int main(int argc, char **argv) {
  std::cout << "Running test..." << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}