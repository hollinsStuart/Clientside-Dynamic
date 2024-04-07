#include "gtest/gtest.h"
#include "mylib/myclass.h"

TEST(MyClassTest, MyMethodReturnsTrue) {
    MyClass my_object;
    EXPECT_TRUE(my_object.MyMethod());
}

TEST(MyClassTest, MyMethodReturnsFalse) {
    MyClass my_object;
    EXPECT_FALSE(my_object.MyMethod(false));
}

