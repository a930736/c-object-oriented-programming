//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 物件參數的傳值與傳參考
//傳參考 & 不會複製物件 也可以當作回傳的方式
//傳值 會呼叫複製建構子 會拖慢程式執行速度
// 13.17


#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *string;
    int len;
    
    
public:
    String(const char *i_string);
    String(String &);
    ~String();
    void show_string();
    
};

void String::show_string()
{
    cout << "string: " << string << " length : " << len <<endl;
}

String::String(const char* i_string)
{
    cout << "Constructor is called!" << endl;
    len = strlen(i_string);
    string = new char[len+1];
    strcpy(string, i_string);
}

String::String(String & a_string) :len(a_string.len)
{
    cout << "Copy constructor is called!" << endl;
    string = new char[len+1];
    strcpy(string, a_string.string);
    
}

String::~String()
{
    cout << "Destructor is called !" <<endl;
    delete [] string;
}

int main()
{
    String call_by_val(String);
//傳值傳遞物件String
    void call_by_ref(String &);
//傳參考方式傳遞物件
    String A_String("My string");
    
    cout << endl << "---------call by reference--------" <<endl;
    cout << "Before executing function...." << endl;
    call_by_ref(A_String);
    cout << endl << "After executing function...." <<endl;
    
    cout << endl << "---------call by value------------" <<endl;
    cout << "Before executing function..." <<endl;
    call_by_val(A_String);
    cout << endl << "After executing function...." << endl;
    
    return 0;
    
}

void call_by_ref(String & aString)
{
    cout << endl << "Executing call_by_ref function..." << endl;
}

String call_by_val(String aString)
{
    cout << endl << "Executing call_by_val function..." <<endl;
    return aString;
}
