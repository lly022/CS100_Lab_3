#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, MixedCharsAndNums) {
        char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "a1b2c3d4"; test_val[2] = "f5h3j2b9x211hgh54p";
        EXPECT_EQ("a1b2c3d4 f5h3j2b9x211hgh54p", echo(3, test_val));
}

TEST(EchoTest, SpecialChars) {
        char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "!@#"; test_val[2] = "$%^"; test_val[3] = "&*(";
        EXPECT_EQ("!@# $%^ &*(", echo(4, test_val));
}

TEST(EchoTest, TripleSpaces) {
        char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "A "; test_val[2] = " B "; test_val[3] = " C ";
        EXPECT_EQ("A   B   C ", echo(4, test_val));
} 

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
