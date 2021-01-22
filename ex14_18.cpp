//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//虛擬繼承 virtual 同時繼承兩個類別時 兩個類別來自同一基礎類別 virtual 可節省空間
// class father : public virtual person
//
// 14.18

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    char last_name[5];
    char first_name[15];
public:
    Person(const char* l_name, const char * f_name)
    {
        strcpy(last_name, l_name);
        strcpy(first_name, f_name);
        
    }
    Person() {}
    void show_data()
    {cout << first_name << " " << last_name; }
};

class Father :  public virtual Person
{
public:
    Father(const char* last_name, const char * first_name) : Person(last_name, first_name) {}
    Father() {}
    char * get_last_name() { return last_name;}
};

class Mother : public virtual Person
{
public:
    Mother(const char * last_name, const char * first_name) : Person(last_name, first_name) {}
    Mother() { }
};

class Child: public Father, public Mother
{
private:
    Father* my_father;
    Mother* my_mother;
public:
    Child(Father & a_father, Mother & a_mother, const char * name);
    void show_data();
};
Child::Child(Father & a_father, Mother & a_mother, const char * name) : my_father( & a_father), my_mother(& a_mother )
{
    strcpy(last_name, a_father.get_last_name());
    strcpy(first_name, name);
    }

void Child::show_data()
{
    cout << "My name is : ";
    Person::show_data();
    cout << endl;
    cout << "My father is : ";
    my_father->show_data();
    cout << endl;
    cout << "My mom is : ";
    my_mother->show_data();
}

int main()
{
    Father a_father("Wang", " David");
    Mother a_mother("Yang" , "Mary");
    Child a_child(a_father, a_mother, "Chi");
    a_child.show_data();
    return 0;
}
