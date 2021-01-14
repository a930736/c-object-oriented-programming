//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 運用const 控制不可修改成員函數的回傳位址指向的值
// 13.11

#include <iostream>
#include <cstring>
using namespace std;

class Reader
{
private:
    char name[10];
public:
    Reader(char* name_)
    {
        strcpy(name, name_);
    }
    
    const char* get_const_name()
    {
        return name;
    }
    
    char * get_name()
    {
        return name;
    }
    void show_name() const
    {
        cout <<"name : " << name << endl;
    }
};

int main()
{
    Reader A_Reader("John");
    const char*  const_reader_name;
    char* reader_name;
    
    const_reader_name = A_Reader.get_const_name();
    // *(const_reader_name + 2) = "c" 錯誤 無法修改指標指向的值
    A_Reader.show_name();
    reader_name = A_Reader.get_name();
    *(reader_name+2) = '2';
    A_Reader.show_name();
    
    return 0;
 }
