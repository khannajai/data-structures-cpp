#include "gtest/gtest.h"
#include "stack.h"

using namespace std;

TEST(testStack, testBack)
{
    stack<int> s;
    s.push(1);
    EXPECT_EQ(1, s.back());
}

GTEST_API_ int main(int argc, char **argv) {
  cout << "Running test..." << endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}