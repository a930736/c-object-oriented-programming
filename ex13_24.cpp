//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// == 運算子 比對兩物件是否相同
// 13.24


#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char * string;
    long len;
    
public:
    
    String(const char *);
    
    bool operator== (String & str)
    {
        return !strcmp(string, str.string);
    }


};


String::String(const char* i_string)
{
    len = strlen(i_string);
    string = new char(len+1);
    strcpy(string, i_string);
    
}

int main()
{
    String A_String("The holy Bible ");
    String B_String("You are my lord!");
    
    if (A_String == B_String)
    {
        cout << "A_String == B_String"<<endl;
    }
    else
    {
        cout << "A_String != B_String" <<endl;
        
    }

    
    return 0;
    
    
}
