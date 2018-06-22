#include "gtest/gtest.h"
#include "dlist.h"

using namespace std;

TEST(testDlist, testFront)
{
    dlist<int> s;
    s.insert_front(1);
    EXPECT_EQ(1, s.show_front());
}

GTEST_API_ int main(int argc, char **argv) {
  cout << "Running test..." << endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}