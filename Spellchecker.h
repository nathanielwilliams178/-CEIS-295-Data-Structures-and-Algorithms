#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

class SpellChecker
{
private:
public:
	unordered_map<string, string> wordDict;
	void Checkfile(const string& filename);
	vector <string>SwapAdjChars(const string& word);
	vector <string>insertChars(const string& word);
	vector <string>deleteChars(const string& word);
	vector <string>replaceChars(const string& word);
	void readDictionaryFile(const string& filename);
};

