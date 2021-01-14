//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 使用const_cast 運算子 解除const 成員函數的const宣告 變成可以改變資料成員
// 13.13


#include <iostream>
#include <cstring>
using namespace std;

class ConstCast
{
private:
    int data;
public:
    ConstCast()
    {
        data = 0;
    }
    int get_data() const;
    
};

int ConstCast::get_data() const
{
    const_cast <ConstCast*>(this) ->data += 1;
    
//const_cast運算子將 const ConstCast* 的this改成 ConstCast*
    return data;
}

int main()
{
    ConstCast Object;
    cout << "Data is " << Object.get_data() << " ." <<endl;
    return 0;
}
