//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// []運算子
// 13.23


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
    char operator[] (int num);//多載 ＝運算子

    
    
};

void String::show_string()
{
    cout << "String : " << string ;
    cout << " length : " << len ;

    
}

String::String(const char* i_string)
{
    len = strlen(i_string);
    string = new char(len+1);
    strcpy(string, i_string);
    
}

char  String::operator[](int num)
{
    if (num > len)
    {
        num = len - 1 ;
    }
    else if (num < 0 )
    {
        num = 0;
    }
    
    return string[num];
}

int main()
{
    String A_String("The holy Bible ");
    A_String.show_string();
    cout << "A_String[5] = " << A_String[5] << endl;
    cout << "A_String[1] = " << A_String[1] << endl;
    cout << "A_String[0] = " << A_String[0] << endl;

    
    return 0;
    
    
}
