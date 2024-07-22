#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removePunct(const string& s);
string makeLower(string s);
bool letterCounter(string s, string t);
bool compareLetterCounts(int arrayS[], int arrayT[], int size);


int main()
{
    cout << "Enter a word, phrase, or sentence: \n";
    string string1;
    getline(cin, string1);
    cout << "Now enter another word, phrase, or sentence: \n";
    string string2;
    getline(cin, string2);

    string1 = removePunct(string1);
    string1 = makeLower(string1);

    string2 = removePunct(string2);
    string2 = makeLower(string2);

    if(letterCounter(string1, string2))
    {
        cout << string1 << " and " << string2 << " are anagrams! :)\n";
    }
    else
    {
        cout << string1 << " and " << string2 << " are NOT anagrams :(\n";
    }

    return 0;
}

string removePunct(const string& s)
{
    string punct(",;:.?!'\" ");
    string noPunct; // initialized to empty string
    int sLength = s.length();
    int punctLength = punct.length();
    for (int i = 0; i < sLength; i++)
    {
        string aChar = s.substr(i,1); // a one-character string
        int location = punct.find(aChar, 0); // find location of successive characters

        if (location < 0 || location >= punctLength)
        {
            noPunct = noPunct + aChar; //aChar is not in punct, so keep it
        }
    }
    return noPunct;
}

string makeLower(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool letterCounter(string s, string t)
{

    int specificLetterCount;
    int sLetterCountArray[27] = {0};
    int tLetterCountArray[27] = {0};

    for (int i = 0; i < 26; i++)
    {
        int asciiNum = i + 97;
        char charLetter = static_cast<char>(asciiNum);
        specificLetterCount = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == charLetter)
            {
                specificLetterCount++;
            }
        }
        sLetterCountArray[i] = specificLetterCount;
        asciiNum = static_cast<int>(charLetter);
    }

    for (int i = 0; i < 26; i++)
    {
        int asciiNum = i + 97;
        char charLetter = static_cast<char>(asciiNum);
        specificLetterCount = 0;
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == charLetter)
            {
                specificLetterCount++;
            }
        }
        tLetterCountArray[i] = specificLetterCount;
        asciiNum = static_cast<int>(charLetter);
    }

    if(compareLetterCounts(sLetterCountArray, tLetterCountArray, 27))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compareLetterCounts(int arrayS[], int arrayT[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arrayS[i] != arrayT[i])
        {
            return false;
            break;
        }
    }
    return true;
}

