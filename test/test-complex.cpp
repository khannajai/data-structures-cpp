#include "gtest/gtest.h"
#include "complex.h"

TEST(testComplex, testReal)
{
    complex c(1,1);
    EXPECT_EQ(1,c.getReal());
}

GTEST_API_ int main(int argc, char** argv)
{
    std::cout<<"Running tests..."<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}