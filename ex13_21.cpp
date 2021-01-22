//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// = 運算子
// 13.21


#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char * string;
    long len;
public:
    String();
    String(const char *);
    void show_string();
    String & operator= (const String &);//多載 ＝運算子
    
};

void String::show_string()
{
    cout << "String : " << string << "string address: ";
    cout << (void *)string;
    cout << " length : " << len <<endl;
    
}
String::String()
{
    len = 0;
    string = new char[len+1];
    string[0]= '\0';
}
String::String(const char* i_string)
{
    len = strlen(i_string);
    string = new char(len+1);
    strcpy(string, i_string);
    
}

String & String::operator=(const String & str)
{
    cout << "overloading operator"<< endl;
    delete string;
    len = str.len;
    string = new char[len+1];
    strcpy(string, str.string);
    return *this;
    
}
int main()
{
    String A_String("My String");
    String B_String;
    
    B_String = A_String;
    
    cout << "A_String....."<< endl;
    A_String.show_string();
    
    cout << "B_String...."<<endl;
    B_String.show_string();
    return 0;
    
    
}
