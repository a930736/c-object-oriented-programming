//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//this 指標 指向物件自己本身 可以表達物件儲存在記憶體內的位置
// 13.18


#include <iostream>
#include <cstring>
using namespace std;

class this_ptr
{
private:
    long index;
public:
    void show_address()
    {
        cout << "The address of 'this' pointer: " << this <<endl;
    }
};

int main()
{
    this_ptr object;
    cout << "The address of object : " << &object << endl;
    object.show_address();
    return 0;
    
}
