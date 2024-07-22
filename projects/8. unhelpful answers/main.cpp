#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

ifstream inStream;
ofstream outStream;

string filename = "answers.txt";
string question;  // Q: can this be made local?
string answer;   // Q: can this be made local?

bool openCheck();
void answerQuestion(int& fileIteration);
void newLine(std::istream& inStream, std::ostream& outStream, int& fileIteration);

const int NUMBER_OF_CHAPTERS = 20;
string toBeReplaced = "#N"; 

int main()
{
    string filename = "answers.txt";
    ifstream file(filename);

    int fileIteration = 0;

    if (openCheck())
    {
        answerQuestion(fileIteration);
    }
    else
    {
        exit(1);
    }
}

bool openCheck()
{
    inStream.open(filename);
    if(inStream.fail())
    {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }
    else
    {
        return true;
    }
}

void answerQuestion(int& fileIteration)
{
    do
    {
        cout << "Type in any one-line question or press 1 to exit: ";

        getline(cin, question);

        if ((question == "1"))
        {
            exit(0);
        }

        if (inStream.eof())
        {
            inStream.close();
            openCheck();
            fileIteration++;
        }

        newLine(inStream, outStream, fileIteration, answer);  // TODO: correct order - before getline, correct?  ALSO: not sure how to optimize this, but this will have to do for now (for each answer)
        (getline(inStream, answer));

        cout << answer << endl; // TODO: placement in context of above
    } while (true);
}

void newLine(istream& inStream, ostream& outStream, int& fileIteration, string answer) // TODO: do i need outStream?
{
    for (int lineNum = 1; lineNum <= 8; lineNum++)
    {
        if (lineNum - 1 == 0)
        {
            int replacement = NUMBER_OF_CHAPTERS - fileIteration;
            if (replacement == 0)
            {
                replacement += 20;
            }

            

            for(int i = 0; i < ______.length(); i++) // TODO: need variable on this line
            {
                if(______[i] == toBeReplaced)
                {
                    ________[i] == replacement; 
                }
            }

            getline(inStream, answer);
            // TODO: cout

        }

        else
        {
            getline(inStream, answer);
             // TODO: cout
        }
    }

}




/* void newLine(std::istream& inStream, std::ostream& outStream, int& fileIteration)
{
    char chapter; 
    do
    {
        inStream.get(chapter);
        int number = (NUMBER_OF_CHAPTERS - fileIteration);
        string str = to_string(number);

        outStream << str; 

    } while (chapter == 'N');
}
*/
