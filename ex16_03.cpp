//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 動態連結與虛擬函數 透過virtual
// 16.3

#include <iostream>
#include <cstring>
using namespace std;

class person;

class object
{
protected:
    char color[10];
    char type[10];
public:
    object(char * _type, char * _color)
    {
        strcpy(color, _color);
        strcpy(type, _type);
    }
    object() {}
    
    virtual void set_object(person & a_person)
    {
        cout << "The set_object(person & a_person) of object is called" <<endl;
    }
};

class clothes;
class pants;
class shoes;

class person
{
protected:
    char last_name[5];
    char first_name[15];
    clothes * a_clothes;
    pants * a_pants;
    shoes * a_shoes;
    friend class clothes;
    friend class pants;
    friend class shoes;
public:
    person(const char * l_name, const char * f_name)
    {
        strcpy(last_name,l_name);
        strcpy(first_name, f_name);
    }
    void wear(object &object)
    {
        cout << "The wear(object &object) of person is called !" <<endl;
        object.set_object(*this);
    }
    void show_data();
};

class shoes :public object
{
private:
    friend class person;
public:
    shoes(char* _type, char * _color) : object(_type, _color){}
    
    void set_object(person & a_person)
    {
        cout << "The set_object() of shoe is called!" <<endl;
        a_person.a_shoes = this;
    }
};

class clothes: public object
{
private:
    friend class person ;
public:
    clothes(char *type, char * color): object(type, color){}

    void set_object(person & a_person)
    {
        cout << "The set_object of clothes is called!"<<endl;
        a_person.a_clothes = this ;
    }
    
    
};


class pants: public object
{
private:
    friend class person ;
public:
    pants(char *type, char * color): object(type, color){}
    
    void set_object(person & a_person)
    {
        cout << "The set_object of pants is called!"<<endl;
        a_person.a_pants = this ;
    }
    
    
};



void person::show_data()
{
    cout <<"My name is " <<last_name << first_name <<endl;
    cout <<"I wear a " <<a_clothes->color <<" "  << a_clothes->type ;
    cout << ", a " << a_pants->color << " " << a_pants->type ;
    cout << " and " << a_shoes->color << " " << a_shoes->type << endl;
    
}


int main()
{
    person David("David", "Wang");
    object a_object;
    clothes a_clothes("T shirt" , "white");
    pants a_pants("short", "green");
    shoes a_shoes("gym shoes", "blue");
    
    cout << "The first testing...... " << endl;
    David.wear(a_object);
    cout <<endl;
    
    cout << "The second testing.... " <<endl;
    
    David.wear(a_clothes);
    David.wear(a_pants);
    David.wear(a_shoes);
    
    David.show_data();
    
    return 0;
    
    
}
