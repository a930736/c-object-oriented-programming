//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//運用this 指標回傳物件
// 13.19


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
        cout << "index : " << index <<endl;
    }
    this_ptr * set_index(long i_index)
    {
        index = i_index;
        return this;
    }
};

int main()
{
    this_ptr object, *object_ptr;
    object_ptr = object.set_index(1);
    cout << "object address : " << &object << endl;
    cout << "pointer : " << object_ptr << endl;
    object.set_index(2)->show_address();
    
    
    
    return 0;
    
}
