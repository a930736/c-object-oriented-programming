//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 複製建構子 執行複製物件的工作
//

#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* string;
    long len;
    
public:
    String();
    String(const char* i_string);
    String(String & a_string);
    void show_string();
    
};

void String::show_string()
{
    cout << "string : " << string << "length : " << len <<endl;
    
}
String::String()
{
    cout << "Define constructor is called! " << endl;
    
}

String::String(const char* i_string)
{
    len = strlen(i_string);
    cout << "Constructor is called !" << endl;
    string = new char[len + 1];
    strcpy(string,i_string);
    
}

// 複製建構子
String::String(String & a_string): len(a_string.len)
{
    cout <<"Copy constructor is called! " <<endl;
    string = new char[len+1];
}

int main()
{
    String A_String("My string");
    String B_String(A_String);
    String C_String;
    
    
    
    cout << "A_String: " << endl;
    A_String.show_string();
    
    cout << "B_String: " << endl;
    B_String.show_string();
    
    cout << "C_String: " << endl;
    C_String.show_string();
    
    return 0;
}
