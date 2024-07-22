#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class BoxOfProduce
{
public:
    BoxOfProduce(int s) : size(s), fruitsAndVeggiesBundle(s, "") { }
    bool getProduce(const string &filename);
    void setReplacement();
    friend BoxOfProduce operator+(const BoxOfProduce& box1, const BoxOfProduce& box2);  // question: why "friend"?
    void output();

private:
    int size;
    vector<string> fruitsAndVeggiesBundle;
};

bool getAdditions();

int main()
{
    BoxOfProduce boxMain(3);

    string filename = "produce.txt";
    if(boxMain.getProduce(filename))
    {
        boxMain.output();
        boxMain.setReplacement();
    }

    int numAdditions = 0;
    char charAdditions;
    if(getAdditions())
    {
        cout << "Type the number of desired additions (e.g., 1, 2, 3, etc.):\n";
        cin >> charAdditions;
    }
    else
    {
        boxMain.output();
    }

    numAdditions = charAdditions - '0';
    BoxOfProduce boxAdditions(numAdditions);

    if(boxAdditions.getProduce(filename))
    {
        BoxOfProduce boxCombined = boxMain + boxAdditions;
        boxCombined.output();
    }

    return 0;
}

bool BoxOfProduce::getProduce(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }

    for(int i = 0; i < size; ++i)
    {
        if(!(file >> fruitsAndVeggiesBundle[i]))
        {
            cerr << "Error reading data from file or not enough data." << endl;
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}



void BoxOfProduce::output()
{
    cout << "Here are the contents of your box to be delivered: " << endl;
    for(int i = 0; i < size; ++i)
    {
        cout << fruitsAndVeggiesBundle[i] << " ";
    }
    cout << endl;
}

void BoxOfProduce::setReplacement()
{
    cout << "Would you like to replace a fruit or veggie (y/n)?\n";
    char answer;
    cin >> answer;
    if(answer == 'y')
    {
        cout << "Please specify the fruit or veggie you would like to change.\n";
        string selection;
        cin >> selection;
        cout << "Now specify what you would like to replace it with. Options include: Peach, Microgreens, Mango, Radish, or Tangerine, Papaya, Dragonfruit, Guava, or Cucumber.\n";
        string replacement;
        cin >> replacement;

        for(size_t i = 0; i < fruitsAndVeggiesBundle.size(); ++i)
        {
            if(fruitsAndVeggiesBundle[i] == selection)
            {
                fruitsAndVeggiesBundle[i] = replacement;
                break;
            }
        }

    }
}

BoxOfProduce operator +(const BoxOfProduce& box1, const BoxOfProduce& box2)
{
    BoxOfProduce combined(box1.size + box2.size); // question: important to study .size here

    for(int i = 0; i < box1.size; ++i)
    {
        combined.fruitsAndVeggiesBundle[i] = box1.fruitsAndVeggiesBundle[i]; // check why this is the case
    }

    for(int i = 0; i < box2.size; ++i)
    {
        combined.fruitsAndVeggiesBundle[box1.size + i] = box2.fruitsAndVeggiesBundle[i];
    }

    return combined;
}


bool getAdditions()
{
    cout << "Would you like to add more fruits or veggies? (y/n)\n";
    char answer;
    cin >> answer;
    if(answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

