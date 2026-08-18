// Chapter13_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

public:
    string getName() { return m_name; }

    virtual void speak() const = 0; // pure virtual function

/*    virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }*/
};

class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Meow" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Woof" << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Moo" << endl;
    }
};

class IErrorLog
{
public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public: 
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file " << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Priting error to a console " << endl;
        return true;
    }
};

void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
    Cow cow("Hello");
    cow.speak();
    cout << endl;

    FileErrorLog file_log;
    ConsoleErrorLog  console_log;

    doSomething(file_log);
    doSomething(console_log);

    return 0;
}

