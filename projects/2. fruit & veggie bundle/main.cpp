#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BoxOfProduce
{
public:
    bool getProduce(const string &filename);

    void setReplacement();
    void output();

private:
    static const int size = 3;
    string fruitsAndVeggiesBundle[size];
};


int main()
{
    BoxOfProduce box;

    string filename = "produce.txt";
    if(box.getProduce(filename))
    {
        box.output();
        box.setReplacement();
        box.output();
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
        cout << "Now specify what you would like to replace it with. Options include: Peach, Microgreens, Mango, Radish, or Tangerine.\n";
        string replacement;
        cin >> replacement;

        for(int i = 0; i < size; i++)
        {
            if(fruitsAndVeggiesBundle[i] == selection)
            {
                fruitsAndVeggiesBundle[i] = replacement;
                cout << "found.\n";

                break;
            }
        }
    }
}




