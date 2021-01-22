//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// 13.20


#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char * string;
    long len;
public:
    String(const char *);
    void show_string();
    
};

void String::show_string()
{
    cout << "String : " << string << "string address: ";
    cout << (void *)string;
    cout << "length : " << len <<endl;
    
}
String::String(const char* i_string)
{
    len = strlen(i_string);
    string = new char(len+1);
    strcpy(string, i_string);
    
}

int main()
{
    String A_String("The C++ Bible");
    String * B_String = new String("C++ Explanied");
    A_String = *B_String;
    cout << "A_String....."<< endl;
    A_String.show_string();
    
    cout << "B_String...."<<endl;
    B_String->show_string();
    return 0;
    
    
}
