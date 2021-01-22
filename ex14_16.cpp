//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多重繼承
// 類別::資料成員
// 類別::成員函數
// 14.16

#include <iostream>
#include <cstring>
using namespace std;

class father
{
protected:
    char last_name[5];
    char first_name[15];
public:
    father(const char* f_name, const char* l_name)
    {
        strcpy(last_name, l_name);
        strcpy(first_name, f_name);
    }
    father() {}
    char * get_last_name() { return last_name ;}
    
    void show_data() {cout << first_name<<"  "<< last_name <<" " <<endl;}
};

class mother
{
protected:
    char last_name[5];
    char first_name[15];
public:
    mother(const char * f_name, const char * l_name)
    {
        strcpy(last_name, l_name);
        strcpy(first_name, f_name);
    }
    mother() {}
    
    void show_data()
    {
        cout << first_name <<" " << last_name;
    }
};

class child : public father, public mother
{
private:
    father * my_father;
    mother * my_mother;
public:
    child(father & , mother &, const char * );
    void show_data();
    
    
};

child::child(father & a_father, mother & a_mother, const char * name) : my_father(& a_father), my_mother(& a_mother)
{
    strcpy(father::last_name, a_father.get_last_name());
    strcpy(father::first_name, name);
}

void child::show_data()
{
    cout << "My name is : ";
    father::show_data();
    cout << endl;
    cout << "My father is : " ;
    my_father->show_data();
    cout << endl;
    cout << "My mother is : ";
    my_mother->show_data();
    cout << endl;
    
}
int main()
{
    father a_father("David", "Kung");
    mother a_mother("Mary", "Yang");
    child a_child(a_father, a_mother, "Chi");
    a_child.show_data();
    return 0;
}
