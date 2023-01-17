#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

/*TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
} */

TEST_CASE( "testing adding a single word", "[Add]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
	REQUIRE(b.add("hello"));
	REQUIRE(!b.add("hello "));
	REQUIRE(!b.add("HeLLo")); 
} 

TEST_CASE( "cut test 1", "[cutTest1]" )
{
	FindPalindrome b;
	std::vector<std::string> testVec= {"Was", "iT", "a", "rAt", "i", "saw"};
	std::vector<std::string> testVec2= {"was", "tt", "a", "cat", "i", "saw"};
	REQUIRE(b.cutTest1(testVec));
	REQUIRE(!b.cutTest1(testVec2));	
} 

TEST_CASE( "cut test 2", "[cutTest2]" )
{
	FindPalindrome b;
	std::vector<std::string> testVec= {"wAs", "it", "a"};
	std::vector<std::string> testVec2= {"Rat", "i", "Saw"};
	std::vector<std::string> testVec3= {"was", "it" , "b"};
	std::vector<std::string> testVec4= {"rat", "ic", "saw"};

	REQUIRE(b.cutTest2(testVec, testVec2));
	REQUIRE(!b.cutTest2(testVec3, testVec4));	
} 
TEST_CASE( "Find Palindrome test", "[FindPalindrome]" )
{
	FindPalindrome b;
	b.add("wAs");
	b.add("it");
	b.add("a");
	b.add("rat");
	b.add("I");
	b.add("saw");
	REQUIRE(b.number() == 2);
	b.clear();
	b.add("a");
	b.add("AAA");
	b.add("aa");
	REQUIRE(b.number() == 6);
	b.add("aAaA");
	REQUIRE(b.number() == 24);
	b.clear();
	b.add("racecar");
	REQUIRE(b.number() == 1);
	b.clear();
	b.add("was");
	b.add("it");
	b.add("a");
	b.add("rbt");
	b.add("i");
	b.add("sab");
	REQUIRE(b.number() == 0);
} 
TEST_CASE( "toVector", "[toVector]" )
{
	FindPalindrome b;
	b.add("wAs");
	b.add("it");
	b.add("a");
	b.add("rat");
	b.add("I");
	b.add("saw");
	REQUIRE(b.number() == 2);
	std::vector<std::string> v1 = {"wAs", "it", "a", "rat", "I", "saw"};
	std::vector<std::string> v2 = {"saw", "it", "a", "rat", "I", "wAs"};
	std::vector<std::vector<std::string>> v3 = {v1, v2}; 
	REQUIRE(b.toVector() == v3);
}
TEST_CASE( "Find Palindrome test with vectors", "[FindPalindrome]" )
{
	FindPalindrome b;
	b.add("it");
	b.add("wAs");
	b.add("a");
	std::vector<std::string> v1 = {"rat", "I", "saw"};
	b.add(v1);
	REQUIRE(b.number() == 2);
	b.clear();
	std::vector<std::string> v2 = {"a", "aa", "AaA"};
	b.add(v2);
	REQUIRE(b.number() == 6);
	b.add("aAaA");
	REQUIRE(b.number() == 24);
	b.clear();
	b.add("it");
	b.add("wAs");
	b.add("a");
	std::vector<std::string> v3= {"it"};
	REQUIRE(b.add(v3) == false);
} 