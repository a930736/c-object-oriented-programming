//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//物件關係的選擇
// 15.4

#include <iostream>
#include <cstring>
using namespace std;

class person
{
protected:
    char last_name[20];
    char first_name[20];
public:
    person(const char * fi_name, const char * la_name)
    {
        strcpy(last_name, la_name);
        strcpy(first_name, fi_name);
    }
    person() {}
    
    void show_data()
    {
        cout << first_name << "  " << last_name <<endl;
    }
};

class father : public virtual person
{
public:
    
    father(const char * fi_name, const char * la_name):person(fi_name, la_name)
    {}
    father() {}
    char * get_last_name()
    {
        return last_name;
    }
};

class mother : public virtual person
{public:
    
    mother(const char * fi_name, const char * la_name):person(fi_name, la_name)
    {}
    mother() {}
};

class child :public mother, public father
{
private:
    father & my_father;
    mother & my_mother;
public:
    child(father & a_father, mother & a_mother, const char * );
    
    void show_data() ;
};
child::child(father & a_father, mother & a_mother, const char * _name):my_father(a_father), my_mother(a_mother)
{
    strcpy(last_name, a_father.get_last_name());
    
    strcpy(first_name, _name);
}

void child::show_data()
{
    person::show_data();
}

class family
{
private:
    father & a_father;
    mother & a_mother;
    child ** child_list;
    int num;
    
public:
    family(father & a_father, mother & a_mother, child ** a_child_list, int num):a_father(a_father), a_mother(a_mother), num(num)
    {
        child_list = new child * [num];
        
        
        for (int i = 0; i < num ; i++)
        {
            child_list[i] = *(a_child_list +i);
        }
    }
    void show_family()
    {
        cout << "Father is  " ;
        a_father.show_data();
        cout << endl;
        cout << "Mother is : ";
        a_mother.show_data();
        
        cout << endl;
        cout << "There are " << num << " children." << endl;
        cout << "They are ...." <<endl;
        for (int i = 0; i < num ; i++)
        {
            child_list[i]->show_data();
            cout << endl;
            
        }
    }
    ~family()
    {
        delete child_list;
    }
};

int main()
{
    father a_father("David", "Wang");
    mother a_mother("Mary", "Yang");
    child * children[2];
    
    children[0] = new child(a_father, a_mother, "Josh");
    children[1] = new child(a_father, a_mother, "Julia");
    family a_family(a_father, a_mother, children, 2);
    
    a_family.show_family();
    
    return 0;
}
