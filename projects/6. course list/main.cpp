#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student(string name1, int num1) : name(name1), numClasses(num1);
    void setName(string newName)
    void setNumClasses(int newNumClasses);
    void setClassList();
    string getName();
    void getNumClasses();
    void getClassList();
    void input();
    void reset();
    void output();
    Student operator=(const Student& other); // INVESTIGATE: ensure I understand - scroll below
    Student(const Student& other) : name(other.name), numClasses(other.numClasses); // INVESTIGATE: ensure I understand - scroll below
    ~Student();

private:
    string name;
    int numClasses;
    string* classList;
};

Student myStudent("", 0);

int main()
{
    input();
    output();
    cout << "Would you like to reset, or re-type, your classes? (y/n)\n";
    cin >> char answer;
    if(answer = 'y')
    {
        reset();
        input();
        output();
    }
    else if
    {
        return 0;
    }

    return 0;
}

Student::Student(string name1, int num1) : name(name1), numClasses(num1)
{
    classList = new string[num1]; // INVESTIGATE: understand what this syntax within the constructor declaration means

    for (int i = 0; i < num1; ++i)
    {
        classList[i] = i * 10;
    }
}

void: Student::input()
{
    cout << "Please enter your name:\n";
    getline(cin, name1);
    setName(name1);

    cout << "Please enter the number of classes:\n";
    getline(cin, num1);
    setNumClasses(num1);

    setClassList();
}

void Student::setName(string newName)
{
    name = newName;
}

void Student::setNumClasses(int newNumClasses)
{
    numClasses = newNumClasses;
}

string Student::getName()
{
    return name;
}

void Student::getNumClasses()
{
    return numClasses;
}

void Student::getClassList()
{
    return classList;
}

void Student::setClassList()
{
    cout << "Please enter each class followed by a press of the return key:\n";
    for (int i = 0; i < NumClasses; ++i)
    {
        getline(cin, numClasses[i]);
    }
}

Student::Student operator=(const Student &other)
{
    if (this != &other)
    {
    }
    return *this;
}

void Student::reset()
{
    numClasses = 0;
    count = 0;
    for(int i = 0; i < numClasses; ++i)
    {
        classList[i] = 0;
    }
}

void Student::output()
{
    cout << "Here is your final information:\n";
    cout << "Name: " << myStudent.getName() << endl;
    cout << "Courses: \n" << myStudent.getClassList() << endl;
    int index;
    int count = myStudent.getNumClasses();
    for(index = 0; index < count; index++)
    {
        cout << myStudent[index] << "\n";
    }
}

Student::Student& operator=(const Student& other)
{
    if(this != &other)
    {
        delete[] classList;

        name = other.name;
        numClasses = other.numClasses;

        if(numClasses > 0)
        {
            classList = new string[numClasses];
            for(int i = 0; i < numClasses; ++i)
            {
                classList[i] = other.classList[i];
            }
        }
        else
        {
            classList = nullptr;
        }
    }
    return *this;
}

Student::Student(const Student& other) : name(other.name), numClasses(other.numClasses)
{
    if(numClasses > 0)
    {
        classList = new string[numClasses];
        for(int i = 0; i < numClasses; ++i)
        {
            classList[i] = other.classList[i];
        }
    }
    else
    {
        classList = nullptr;
    }
}

Student::~Student()
{
    delete []classList;
}
