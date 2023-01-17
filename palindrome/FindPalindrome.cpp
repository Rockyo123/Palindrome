#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function.
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	if(currentStringVector.size() == 0)
	{
		string temp = "";
		for(unsigned i = 0; i < candidateStringVector.size(); i++)
		{
			temp = temp + candidateStringVector[i];
		}
		if(isPalindrome(temp))
		{
			numPal++;
			palindromes.push_back(candidateStringVector);
		}
	}
	else
	{
		for(unsigned i = 0; i<currentStringVector.size(); i++)
		{
			vector<string> testCur = currentStringVector;
			vector<string> testCan = candidateStringVector;
			testCan.push_back(testCur[i]);
			testCur.erase(testCur.begin() + i);
			if(cutTest2(testCan, testCur))
			{
				recursiveFindPalindromes(testCan, testCur);
			}

		}
	}
}

// private function to determine if a string is a palindrome
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	numPal = 0;
}

FindPalindrome::~FindPalindrome()
{
	clear();
}

int FindPalindrome::number() const
{
	return numPal;
}

void FindPalindrome::clear()
{
	numPal = 0;
	currentSentence.clear();
	palindromes.clear();
	currentPalindrome.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	int letCount = 0;
	int numOdds = 0;
	char curLet;
	vector<string>testStringVector = stringVector;
	for(int i = 0; i < testStringVector.size(); i++)
	{
		convertToLowerCase(testStringVector[i]);
	}
	for(int i = 0; i < testStringVector.size(); i++)
	{
		for(int j = 0; j < testStringVector[i].size(); j++)
		{
			letCount = 0;
			curLet = testStringVector[i][j];
			for(int l = 0; l < testStringVector.size(); l++)
			{
				for(int k = 0; k < testStringVector[l].size(); k++)
				{
					if(curLet == testStringVector[l][k])
					{
						letCount++;
					}
				}
			}
			if(letCount%2 == 1)
			{
				numOdds++;
			}
		}
	}
	if(numOdds > 1)
	{
		return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	vector<string>testStringVector1 = stringVector1;
	string testVec1;
	vector<string>testStringVector2 = stringVector2;
	string testVec2;
	string longer;
	string shorter;
	char let;
	int count1;
	int count2;
	for(int i = 0; i < testStringVector1.size(); i++)
	{
		convertToLowerCase(testStringVector1[i]);
		testVec1 = testVec1 + testStringVector1[i];
	}
	for(int i = 0; i < testStringVector2.size(); i++)
	{
		convertToLowerCase(testStringVector2[i]);
		testVec2 = testVec2 + testStringVector2[i];
	}
	if(testVec1.length() > testVec2.length())
	{
		longer = testVec1;
		shorter = testVec2;
	}
	else
	{
		longer = testVec2;
		shorter = testVec1;
	}
	for(int i = 0; i < shorter.length(); i++)
	{
		count1 = 0;
		count2 = 0;
		let = shorter[i];
		for(int j = 0; j<shorter.length(); j++)
		{
			if(shorter[j] == let)
			{
				count1++;
			}
		}
		for (int l = 0; l < longer.length(); l++)
		{
			if(longer[l] == let)
			{
				count2++;
			}
		}
		if (count1 > count2)
		{
			return false;
		}
	}
	return true;
}

bool FindPalindrome::add(const string & value)
{
	string testCase = value;
	convertToLowerCase(testCase);
	string testCaseVec;
	
	bool contains_non_letter = testCase.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
	if(contains_non_letter)
	{
		return false;
	}
	for (int i = 0; i < currentSentence.size(); i++)
	{
		testCaseVec = currentSentence[i];
		convertToLowerCase(testCaseVec);
		if (testCaseVec == testCase)
		{
			return false;
		}
		
	}
	vector<string> testVector;
	currentSentence.push_back(value);
	numPal = 0;
	palindromes.clear();
	if(cutTest1(currentSentence))
	{
		recursiveFindPalindromes(testVector,currentSentence);
	}

	return true;
}	

bool FindPalindrome::add(const vector<string> & stringVector)
{
	string testCase;
	vector<string> testCaseVec1;
	testCaseVec1 = stringVector;
	for(int i = 0; i < testCaseVec1.size(); i++)
	{
		convertToLowerCase(testCaseVec1[i]);
	}
	for(int i = 0; i < stringVector.size(); i++)
	{
		testCase = testCase + stringVector[i];
	}
	convertToLowerCase(testCase);
	vector<string> testCaseVec2;
	testCaseVec2 = currentSentence;
	for(int i = 0; i < testCaseVec2.size(); i++)
	{
		convertToLowerCase(testCaseVec2[i]);
	}
	
	bool contains_non_letter = testCase.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
	if(contains_non_letter)
	{
		return false;
	}
	for (int i = 0; i < currentSentence.size(); i++)
	{
		for(int j = 0; j< testCaseVec1.size(); j++)
		{
			if(i != j)
			{
				if(testCaseVec1[i] == testCaseVec1[j])
				{
					return false;
				}
			}
		}
		for(int l = 0; l < testCaseVec2.size(); l++)
		{
			if(testCaseVec1[i] == testCaseVec2[l])
			{
				return false;
			}
		}
	}
	for(int i = 0; i < stringVector.size(); i++)
	{
	currentSentence.push_back(stringVector[i]);
	}
	numPal = 0;
	palindromes.clear();
	vector<string> testVector;
	if(cutTest1(currentSentence))
	{
		recursiveFindPalindromes(testVector,currentSentence);
	}

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromes;
}

