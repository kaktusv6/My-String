#include <iostream>
#include <gtest/gtest.h>
#include "String.cpp"

using namespace std;

class StringTest : public ::testing::Test
{
protected:
	String string1, string2;
	void SetUp()
	{  }
};
TEST_F(StringTest, TestOperatorEqual)
{
	string1 = String("asd");
	string2 = String("asd");
	ASSERT_TRUE(string1 == string2);

	string1 = String("The to do");
	string2 = String("The to do");
	ASSERT_TRUE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do door home words Hi, hello!&&&??");
	ASSERT_TRUE(string1 == string2);

	string1 = String("");
	string2 = String("");
	ASSERT_TRUE(string1 == string2);

	string1 = String(" ");
	string2 = String(" ");
	ASSERT_TRUE(string1 == string2);

	string1 = String("     d   ");
	string2 = String("     d   ");
	ASSERT_TRUE(string1 == string2);

	string1 = String("     d   f");
	string2 = String("     d   f");
	ASSERT_TRUE(string1 == string2);

	string1 = String("TOGO");
	string2 = String("TODO");
	ASSERT_FALSE(string1 == string2);

	string1 = String("TODO");
	string2 = String("TODO ");
	ASSERT_FALSE(string1 == string2);

	string1 = String("     d   s");
	string2 = String("     d   f");
	ASSERT_FALSE(string1 == string2);

	string1 = String("    ");
	string2 = String("     ");
	ASSERT_FALSE(string1 == string2);
}
TEST_F(StringTest, TestOperatorInequal)
{
	string1 = String("asd");
	string2 = String("asf");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do");
	string2 = String("The to do world");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do dooe home words Hi, hello!&&&??");
	ASSERT_FALSE(string1 == string2);

	string1 = String("The to do door home words Hi, hello!&&&??");
	string2 = String("The to do dooe!&&&??");
	ASSERT_TRUE(string1 != string2);

	string1 = String("The to home words Hi, hello");
	string2 = String("The to do dooe!&&&??");
	ASSERT_TRUE(string1 != string2);
}
TEST_F(StringTest, TestOperatorAdd)
{
	string1 = String("asd");
	string2 = String("asd");
	ASSERT_EQ(String("asdasd"), string1 + string2);

	string1 = String("q");
	string2 = String("rt");
	ASSERT_EQ(String("qrt"), string1 + string2);

	string1 = String("Hello ");
	string2 = String("my friend!!");
	ASSERT_EQ(String("Hello my friend!!"), string1 + string2);

	string1 = String("foo       ");
	string2 = String("foo       ");
	ASSERT_EQ(String("foo       foo       "), string1 + string2);

	string1 = String("  abcd");
	string2 = String(" dcba");
	ASSERT_EQ(String("  abcd dcba"), string1 + string2);

	string1 = String("abcd");
	string2 = String("dcba");
	ASSERT_EQ(String("abcddcba"), string1 + string2);

	string1 = String("abcdddddddddddd");
	string2 = String("dcba");
	ASSERT_EQ(String("abcdddddddddddddcba"), string1 + string2);

	string1 = String("abcdddddddddddd");
	ASSERT_EQ(String("abcdddddddddddddcba"), string1 + "dcba");

	string1 = String("abcdd");
	ASSERT_EQ(String("abcddcba"), string1 + "cba");

	string1 = String("abcd");
	ASSERT_EQ(String("abcddcba"), string1 + "dcba");

	string1 = String("labudalabuda");
	ASSERT_EQ(String("labudalabudalabuda"), string1 + "labuda");

	string1 = String("abcdd");
	ASSERT_EQ(String("cbaabcdd"), "cba" + string1);

	string1 = String("abcd");
	ASSERT_EQ(String("dcbaabcd"), "dcba" + string1);

	string1 = String("labudalabuda");
	ASSERT_EQ(String("labudalabudalabuda"), "labuda" + string1);
}
TEST_F(StringTest, TestLengthString)
{
	string1 = "abcd";
	ASSERT_EQ(4, string1.size());

	string1 = "lambdalambdalambda";
	ASSERT_EQ(18, string1.size());

	string1 = "labudafignyaigara";
	ASSERT_EQ(17, string1.size());

	string1 = "1";
	ASSERT_EQ(1, string1.size());

	string1 = "12";
	ASSERT_EQ(2, string1.size());

	string1 = "";
	ASSERT_EQ(0, string1.size());
}
TEST_F(StringTest, TestOperatorBrackets)
{
	string1 = "asdlaga";
	ASSERT_EQ('a', string1[0]);
	ASSERT_EQ('s', string1[1]);
	ASSERT_EQ('d', string1[2]);
	ASSERT_EQ('l', string1[3]);
	ASSERT_EQ('a', string1[4]);
	ASSERT_EQ('g', string1[5]);
	ASSERT_EQ('a', string1[6]);

}
TEST_F(StringTest, TestCopy)
{
	string1 = "hello, World!!";
//	cout << string1.copy(0, 2) << endl;
	ASSERT_EQ("he", string1.copy(0, 2));
	ASSERT_EQ("h", string1.copy(0, 1));
	ASSERT_EQ("ello", string1.copy(1, 4));
	ASSERT_EQ("ello", string1.copy(1, 4));
	ASSERT_EQ("o", string1.copy(4, 1));
	ASSERT_EQ("o, W", string1.copy(4, 4));
	ASSERT_EQ("", string1.copy(0, 0));
	ASSERT_EQ("hello, World!!", string1.copy(0, string1.size()));
}
TEST_F(StringTest, TestException)
{
	string1 = "Hello, my name ...";
	ASSERT_THROW(string1[18], Range);
	ASSERT_THROW(string1[19], Range);
	ASSERT_THROW(string1[-1], Range);
	ASSERT_THROW(string1[-10], Range);

	ASSERT_THROW(string1.copy(0, 19), Range);
	ASSERT_THROW(string1.copy(-1, 10), Range);
	ASSERT_THROW(string1.copy(-2, 20), Range);
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}