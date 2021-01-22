//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 重新定義資料成員與存取基礎類別資料成員
// 14.7


#include <iostream>
#include <cstring>
using namespace std;

class Library
{
protected:
    char name[30];
    long index;
public:
    void set_data(const char * i_name)
    {
        strcpy(name, i_name);
        index = 1;
        
    }
};
class Reader : public Library
{
private:
    char name[30];
public:
    void show_data()
    {
        cout << "Reader's name : " << name <<endl;
        cout << "Index : " << index << endl;
        cout << "Library's name : " << Library::name << endl;
        
    }
};

int main()
{
    Reader A_Reader;
    A_Reader.set_data("Eric");
    A_Reader.show_data();
    return 0 ;
    
}
