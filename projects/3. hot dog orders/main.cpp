#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class HotDogStand
{
public:
    HotDogStand(int idValue, int soldThatDayValue);
    void justSold();
    int numberSold();
    void displaySoldByStand();
    /*static int getHotDogsAll();*/ // QUESTION: is this best placement? for some reason, it did not work with me.

private:
    int ID;
    int soldThatDay;
    /*static int hotDogsAll;*/
};

static int hotDogsAll = 0;
char agreement;
char selection;

int addHotDogsAll();

int main()
{
    HotDogStand ardenArcade(1, 0);
    HotDogStand folsomLake(2, 0);
    HotDogStand downtown(3, 0);

    cout << "Welcome to The Hot Dog Stand! You will be given a tour around our locations with an option to make an order at each one.\n\nJoin us? (y/n)\n";
    // QUESTION: how to design code in such a way that gives client options?
    cin >> agreement;
    if(agreement == 'y')
    {
        cout << "\nExcellent!\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "____________________________________________________________\n";
        cout << "\nSTAND 1:\n";
        cout << "\nARDEN-ARCADE\n";
        cout << "____________________________________________________________\n\n";
        cout <<"Make a selection (1, 2, 3, 4):\n\t1. Cheesedog\n\t2. Corndog\n\t3. Vegandog\n\t4. Finish ordering here\n\n";
        selection;
        do
        {
            cin >> selection;
            if(selection == '1' || selection == '2' || selection == '3')
            {
                ardenArcade.justSold();
                addHotDogsAll();
                cout << "\n******************* Order received! ***********************\n\n";
                ardenArcade.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout <<"\nMake another selection.\n";
            }
            else
            {
                cout << "\nReceived.\n";
                ardenArcade.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout << "Onwards to Folsom Lake!\n";
                break;
            }
        }
        while(selection == '1' || selection == '2' || selection == '3');

        this_thread::sleep_for(chrono::seconds(2));
        cout << "____________________________________________________________\n";
        cout << "\nSTAND 2:\n";
            cout << "\nFOLSOM LAKE\n";
        cout << "____________________________________________________________\n\n";
        cout <<"Make a selection (1, 2, 3, 4):\n\t1. Chilidog\n\t2. Veggiedog\n\t3. Cheesedog\n\t4. Finish ordering here\n\n";
        selection;
        do
        {
            cin >> selection;
            if(selection == '1' || selection == '2' || selection == '3')
            {
                folsomLake.justSold();
                addHotDogsAll();
                cout << "\n******************* Order received! ***********************\n\n";
                folsomLake.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout <<"\nMake another selection.\n";
            }
            else
            {
                cout << "\nNoted.\n";
                folsomLake.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout << "Proceed to Downtown!\n";
                break;
            }
        }
        while(selection == '1' || selection == '2' || selection == '3');

        this_thread::sleep_for(chrono::seconds(2));
        cout << "____________________________________________________________\n";
        cout << "\nSTAND 3:\n";
            cout << "\nDOWNTOWN\n";
        cout << "____________________________________________________________\n\n";
        cout <<"Make a selection (1, 2, 3, 4):\n\t1. Lentildog\n\t2. Beandog\n\t3. Beetdog\n\t4. Finish ordering here\n\n";
        do
        {
            cin >> selection;
            if(selection == '1' || selection == '2' || selection == '3')
            {
                downtown.justSold();
                addHotDogsAll();
                cout << "\n******************* Order received! ***********************\n\n";
                downtown.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout <<"\nMake another selection.\n";
            }
            else
            {
                cout << "\nNoted.\n";
                downtown.displaySoldByStand();
                cout << "-----> Total hot dogs ordered across all stands: " << hotDogsAll << endl;
                cout << "Goodbye.\n";
                break;
            }
        }
        while(selection == '1' || selection == '2' || selection == '3');
    }
    else
    {
        cout << "Goodbye, and enjoy your hotdogs!\n";
        exit(0);
    }

    return true;
}

HotDogStand::HotDogStand(int idValue, int soldThatDayValue) : ID(idValue), soldThatDay(soldThatDayValue)
{
    // QUESTION: constructor body to be empty for now?
}

void HotDogStand::justSold()
{
    soldThatDay++;
}

int HotDogStand::numberSold()
{
    return soldThatDay;
    // QUESTION: why does this need to be a member function separate from justSold?
}

void HotDogStand::displaySoldByStand()
{
    cout << "-----> Hot dogs ordered at Stand " << ID << ": " << soldThatDay << " dog(s)\n\n";

}

int addHotDogsAll()
{
    hotDogsAll++;
    return hotDogsAll;
}

/*int HotDogStand::getHotDogsAll()
{
    return hotDogsAll;
} */
