#include <iostream>
#include <gtest/gtest.h>
#include "String.cpp"

class StringTest : public ::testing::Test
{
protected:
	String* string1, *string2;
	void SetUp()
	{  }
};
TEST_F(StringTest, TestOperatorEqual)
{
	string1 = new String("asd");
	string2 = new String("asd");
	ASSERT_TRUE(*string1 == *string2);

	string1 = new String("The to do");
	string2 = new String("The to do");
	ASSERT_TRUE(*string1 == *string2);

	string1 = new String("The to do door home words Hi, hello!&&&??");
	string2 = new String("The to do door home words Hi, hello!&&&??");
	ASSERT_TRUE(*string1 == *string2);
}
TEST_F(StringTest, TestOperatorInequal)
{
	string1 = new String("asd");
	string2 = new String("asf");
	ASSERT_FALSE(*string1 == *string2);

	string1 = new String("The to do");
	string2 = new String("The to do world");
	ASSERT_FALSE(*string1 == *string2);

	string1 = new String("The to do door home words Hi, hello!&&&??");
	string2 = new String("The to do dooe home words Hi, hello!&&&??");
	ASSERT_FALSE(*string1 == *string2);

	string1 = new String("The to do door home words Hi, hello!&&&??");
	string2 = new String("The to do dooe!&&&??");
	ASSERT_TRUE(*string1 != *string2);

	string1 = new String("The to home words Hi, hello");
	string2 = new String("The to do dooe!&&&??");
	ASSERT_TRUE(*string1 != *string2);
}
TEST_F(StringTest, TestOperatorAdd)
{
	string1 = new String("asd");
	string2 = new String("asd");
	EXPECT_EQ(String("asdasd"), *string1 + *string2);

	string1 = new String("q");
	string2 = new String("rt");
	EXPECT_EQ(String("qrt"), *string1 + *string2);

	string1 = new String("Hello ");
	string2 = new String("my friend!!");
	EXPECT_EQ(String("Hello my friend!!"), *string1 + *string2);
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}