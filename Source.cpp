/*Nathaniel Williams*/
#include <iostream>
#include <fstream>
#include "SpellChecker.h"

using namespace std;


int main()
{
	SpellChecker spellchecker;
	string sampletext = "sampletext.txt";
	string dicttext = "dictionary.txt";
	spellchecker.readDictionaryFile(dicttext);
	spellchecker.Checkfile(sampletext);



	return 0;

}
