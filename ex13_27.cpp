//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//explicit 建構子 限制不可用型別轉換建構子，阻止編譯器自動執行型別轉換建構子
//
// 13.27


#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * string;
    long len;
public:
    String(const char* i_string);
    explicit String(int = 0);
    ~String()
    {
        delete [] string;
    }
};

String::String (const char * i_string)
{
    len = strlen(i_string);
    string = new char[len+1];
    strcpy(string, i_string);
}

String::String(int size)
{
    cout << "Explicit Constructor!" << endl;
    string = new char[size];
}
void convert(String  a_string)
{
    cout << "Test" <<endl;
}
int main()
{
    String a_string(12);
    convert(String (12));
    return 0 ;
    
}
