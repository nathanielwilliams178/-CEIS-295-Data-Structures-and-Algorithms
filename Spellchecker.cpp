#include "SpellChecker.h"

//Reading the Test File to demonstrate functions
void SpellChecker::Checkfile(const string& filename)
{
	ifstream file;
	file.open(filename);

	if (file.is_open())
	{

		string word;
		while (file >> word)
		{
			cout << word << " ->";
			//if does not result in the last iteration, means word = found
			if (wordDict.find(word) != wordDict.end())
			{
				//case 1 - word was found
				cout << ": Spelled Correctly." << endl;
			}
			else
			{
				vector<string> deleteChar = deleteChars(word);
				vector<string> insertChar = insertChars(word);
				vector<string> replaceChar = replaceChars(word);
				vector<string> swapAdjChar = SwapAdjChars(word);

				vector<string> altWordList; //Vector for complete word list

				altWordList.reserve(deleteChar.size() + insertChar.size() + replaceChar.size() + swapAdjChar.size()); //Preallocate memory

				//Add each word list to the complete list
				altWordList.insert(altWordList.end(), deleteChar.begin(), deleteChar.end());
				altWordList.insert(altWordList.end(), insertChar.begin(), insertChar.end());
				altWordList.insert(altWordList.end(), replaceChar.begin(), replaceChar.end());
				altWordList.insert(altWordList.end(), swapAdjChar.begin(), swapAdjChar.end());

				if (altWordList.size() == 0)
				{
					//NO SPELLING SUGGESTIONS
				}
				else
				{
					cout << ": ";
					for (auto& altWord : altWordList)
					{
						cout << altWord << ", ";
					}
					cout << endl;
				}
			}
		}
	}
	else
	{
		cout << "Error opening: " << filename << endl;
	}
}
//adjacent characters swap
vector<string> SpellChecker::SwapAdjChars(const string& word)
{

	vector<string>result;

	for (int i = 0; i < word.size() - 1; i++)
	{
		string newWord = word;
		swap(newWord[i], newWord[i + 1]);
		if (wordDict.find(newWord) != wordDict.end())
			result.push_back(newWord);
	}
	return result;
}
//insert characters
vector<string> SpellChecker::insertChars(const string& word)
{
	vector<string> result; //List of possible corrections

	if (wordDict.find(word) != wordDict.end())
	{
		//IF WORD IS IN DICTIONARY, NOTHING HAPPENS
	}
	else
	{
		for (int i = 0; i < word.size(); ++i)
		{
			for (int j = 97; j < 123; j++) //97(a) to 122(z) are the ASCII values for lowercase characters
			{
				string copy = word; //Copy of original word
				string temp; //String used to convert from ASCII

				temp = int(j); //Converts ASCII value of "j" into string for string::insert() function

				copy.insert(i, temp); //Inserts new character at positions "i"

				if (wordDict.find(copy) != wordDict.end())
				{
					//IF MODIFIED WORD IS IN DICTIONARY, ADD TO result LIST
					result.push_back(copy);
				}
			}
		}
	}

	return result;
}
//delete a character
vector<string> SpellChecker::deleteChars(const string& word)
{
	vector<string> result; //List of possible corrections

	if (wordDict.find(word) != wordDict.end())
	{
		//IF WORD IS IN DICTIONARY, NOTHING HAPPENS
	}
	else
	{
		for (int i = 0; i < word.size(); i++)
		{
			string copy = word; //Copy of original word

			copy.erase(copy.begin() + i); //Delete character

			if (wordDict.find(copy) != wordDict.end())
			{
				// Check results vector in case word found is a duplicate
				auto it = find(result.begin(), result.end(), copy);
				if (it != result.end()) continue;

				//IF MODIFIED WORD IS IN DICTIONARY, ADD TO result LIST
				result.push_back(copy);
			}
		}
	}

	return result;
}
//replace a character
vector<string> SpellChecker::replaceChars(const string& word)
{
	vector<string> result; //List of possible corrections

	if (wordDict.find(word) != wordDict.end())
	{
		//IF WORD IS IN DICTIONARY, NOTHING HAPPENS
	}
	else
	{
		for (int i = 0; i < word.size(); ++i)
		{
			for (int j = 97; j < 123; j++) //97(a) to 122(z) are the ASCII values for lowercase characters
			{
				string copy = word;
				char c = j;

				copy[i] = c;

				if (wordDict.find(copy) != wordDict.end())
				{
					//IF MODIFIED WORD IS IN DICTIONARY, ADD TO result LIST
					result.push_back(copy);
				}
			}
		}
	}

	return result;
}
//Reading Dictionary File into the Program
void SpellChecker::readDictionaryFile(const string& filename)
{
	ifstream file;
	file.open(filename);

	if (file.is_open())
	{
		string word;
		while (file >> word)
		{


			wordDict.emplace(word, word);
		}
	}
	else
	{
		cout << "Error loading file." << endl;
	}
}


