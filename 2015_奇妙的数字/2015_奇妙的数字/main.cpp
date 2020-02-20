//
//  main.cpp
//  2015_奇妙的数字
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//
/*
 
 奇妙的数字
 
 小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
 你能猜出这个数字是多少吗？
 
 */
#include <iostream>
#include <sstream>
using namespace std;

string i2s(int x){
    stringstream ss;
    string str;
    ss << x;
    ss >> str;
    return str;
}

int main(int argc, const char * argv[]) {
    for(int i=30;i<100;i++)
        for(int j=0;j<10;j++){
            if((i2s(i*i).append(i2s(i*i*i)).find(i2s(j))==string::npos) ||
               i2s(i*i).append(i2s(i*i*i)).size() != 10){
                break;
            }
            if(j == 9){
                cout<<i<<endl;
                cout<<i*i<<" "<<i*i*i<<endl;
            }
        }
    return 0;
}
