//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//類別中有類別 前置宣告
//
// 13.29


#include <iostream>
#include <cstring>
using namespace std;

class wife; //前置宣告wife類別

class husband
{
private:
    char name[10];
    wife * my_wife;// 只能利用指標 因為wife內的成員未定義
public:
  husband(const char * i_name)
    {
        strcpy(name, i_name);
    }
    const char * my_name() {
        return name;
    }
    void wife_is();
    void marry_me(wife &);
};

class wife
{
private:
    char name[10];
    husband* my_husband;
public:
    wife(const char * i_name){ strcpy(name, i_name);}
    void husband_is()
    {
        cout << "My husband is  " << my_husband->my_name() <<endl;
    }
    void get_married(husband * a_husband)
    {
        my_husband = a_husband;
    }
    const char * my_name()
    {
        return name;
    }
};


void husband::wife_is()
{
    cout << "My wife is " <<my_wife->my_name() <<"." << endl;
}

void husband::marry_me(wife & a_wife)
{
    my_wife = & a_wife;
    my_wife->get_married(this);
}
int main()
{
    husband Peter("Peter");
    wife Julian("Julian");
    Peter.marry_me(Julian);
    
    cout << "Julian say : ";
    Julian.husband_is();
    
    cout << "Peter yells happily : " ;
    Peter.wife_is();
    return 0;
}
