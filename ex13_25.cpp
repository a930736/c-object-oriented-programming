//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// 型別轉換運算子  將物件轉換為型別
// 基本型別轉成類別 類別轉基本型別 類別間互轉
// 13.25


#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char * string;
    long len;
    friend void call_by_value(String);
    
public:
    
    String(const char *);
    operator char *()
    {
        cout << "Type convert operator is called!" << endl;
        return string;
        
    }


};


String::String(const char* i_string)
{
    cout <<"Type convert constructor is called!"<<endl;
    len = strlen(i_string);
    string = new char(len+1);
    strcpy(string, i_string);
    
}
void call_by_value(String str)
        {
            cout << str.string << endl;
            
        }
void type_con (char * str)
        {
            cout << str <<endl;
        }
        
int main()
{
    String A_String("The holy Bible "); //型別轉換建構子被呼叫 用字串呼叫
    call_by_value("test"); // 型別轉換建構子被呼叫 因為參數是String型別 然後建立test物件
    type_con(A_String); // ch * 型別轉換運算子被呼叫
    
  

    
    return 0;
    
    
}
