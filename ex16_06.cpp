//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//物件指標陣列應用
// 16.6
//My name is : John
//My major is : Math
//~student() is called !
//~person() is called.
//My name is : Mary
//I teach  : English
//~teacher() is called !
//~person() is called.

#include <iostream>
#include <cstring>
using namespace std;

class person
{
protected:
    char name[10];
public:
    person(char * _name)
    {
        strcpy(name, _name);
    }
    virtual ~person()
    {
        cout <<"~person() is called." <<endl;
    }
    virtual void who_are_you() = 0;
};

class student: public person
{
private:
    char major[15];
    
public:
    student(char * _name, char * _major) :person(_name)
    {
        strcpy(major, _major);
    }
    
    void who_are_you()
    {
        cout << "My name is : " << name <<endl;
        cout << "My major is : " << major <<endl;
    }
    ~student()
    {
        cout <<" ~student() is called !" <<endl;
    }
};

class teacher:public person
{
private:
    char teach[15];
    
public:
    teacher(char* name, char * subject):person(name)
    {
        strcpy(teach, subject);
    }
    void who_are_you()
    {
        cout << "My name is : " << name <<endl;
        cout << "I teach  : " << teach <<endl;
    }
    ~teacher()
    {
        cout <<" ~teacher() is called !" <<endl;
    }
};

int main()
{
    person * pArr[5];
    
    pArr[0] = new student("John","Math");
    pArr[1] = new teacher("Mary","English");
    pArr[2] = new student("David","Science");
    pArr[3] = new teacher("Sophia","PE");
    pArr[4] = new student("Eric","History");
    
    
    for (int i = 0; i < 5 ; i++)
    {
        pArr[i]->who_are_you();
        delete pArr[i];
    }
    return 0;
}
