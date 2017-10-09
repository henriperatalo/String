#include <gtest/gtest.h>
#include "string.h"

TEST(StringLen_TEST,aakkoset)
{
    char String1[]="hei";
	char String2[]="shitti";
	char String3[]="ShItTi";
	
    EXPECT_EQ(3,my_strlen(String1));
	EXPECT_EQ(6,my_strlen(String2));
	EXPECT_EQ(6,my_strlen(String3));
}

TEST(StringLen_TEST,skandit)
{
	char String1[]="Ä";
	char String2[]="åäö";
	char String3[]="ålen ruåtsalainen";
	
    EXPECT_EQ(1,my_strlen(String1));
	EXPECT_EQ(3,my_strlen(String2));
	EXPECT_EQ(17,my_strlen(String3));
}

TEST(StringLen_TEST,merkit)
{
	char String1[]="!#¤%&/=";
	char String2[]="\n";
	char String3[]="\0";
	char String4[]="\123";
	char String5[]="€";
	
    EXPECT_EQ(7,my_strlen(String1));
	EXPECT_EQ(1,my_strlen(String2));
	EXPECT_EQ(0,my_strlen(String3));
	EXPECT_EQ(1,my_strlen(String4));
	EXPECT_EQ(1,my_strlen(String5));
}

TEST(StringLen_TEST,sekoilu)
{
	char String1[]="hihi\125lerjf";
	char String2[]="\0dklöfisdfkldfgjkhsdflkjh sdfkljh sdfkl jhsdfkljhsdfkljhgsdkljhglskdjhg sdklfjglksdjfh gkljsdfh gkljsdhfgkljsdhfklgjsdfhklg jsdhkljg hsdkljfgh sdklfjgh klsdj";
	char String3[]="123\0123";
	char String4[]="123\n523";
	char String5[]="";
	
    EXPECT_EQ(10,my_strlen(String1));
	EXPECT_EQ(0,my_strlen(String2));
	EXPECT_EQ(5,my_strlen(String3));
	EXPECT_EQ(7,my_strlen(String4));
	EXPECT_EQ(0,my_strlen(String5));
}

TEST(StringLen_TEST,numerot)
{
	char String1[]="123\0123";
	char String2[]="123\n523";
	char String3[]="0x540x45";
	char String4[]="0x54\0x45";
	char String5[]="0x54\x45";
	char String6[]="x54\x45";
	
	
    EXPECT_EQ(5,my_strlen(String1));
	EXPECT_EQ(7,my_strlen(String2));
	EXPECT_EQ(8,my_strlen(String3));
	EXPECT_EQ(4,my_strlen(String4));
	EXPECT_EQ(5,my_strlen(String5));
	EXPECT_EQ(4,my_strlen(String6));
}



TEST(StringCopyTest,Normal)
{
  char myStr[100] = "hei";
  char dst[100] = "";

  mystrcpy(myStr,dst);
  EXPECT_STREQ(dst,myStr);
   
}

TEST(StringCopyTest,Kreisi)
{
  char myStr[100] = "@*$**";
  char dst[100] = "";

  mystrcpy(myStr,dst);
  EXPECT_STREQ(dst,myStr);
}

TEST(StringCompTest,Normal)
{
	char s[100] = "abc";
	char d[100] = "abc";

	EXPECT_EQ(0,mystrcmp(s,d));
}

TEST(StringCompTest,Kreisi)
{
	char s[100] = "abc";
	char d[100] = "123";

	EXPECT_EQ(1,mystrcmp(s,d));
}

TEST(StringUpperTest,Normal)
{
	char s[100] = "abc";
	str2upper(s);
	EXPECT_STREQ("ABC",s);
}

TEST(StringUpperTest,Kreisi)
{
	char s[100] = "aBBBcC1";
	str2upper(s);
	EXPECT_STREQ("ABBBCC1",s);
}

TEST(StringLowerTest,Normal)
{
	char s[100] = "ABC";
	str2lower_(s);
	EXPECT_STREQ("abc",s);
}

TEST(StringLowerTest,Kreisi)
{
	char s[100] = "aBBBcC1";
	str2lower_(s);
	EXPECT_STREQ("abbbcc1",s);
}

TEST(StringDuplTest,Normal)
{
	char s[100] = "abcdefgh";

	EXPECT_STREQ("abcdefgh",strdupl(s));
}

TEST(StringStripTest,Normal)
{
	char s[100] = "abc1de2fgh";

	EXPECT_EQ(8,str_strip_numbers(s));
}
