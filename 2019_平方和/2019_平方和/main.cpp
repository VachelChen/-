//
//  main.cpp
//  2019_平方和
//
//  Created by VachelChen on 2020/2/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//

//小明对数位中含有2、0、1、9 的数字很感兴趣，在1 到40 中这样的数包
//括1、2、9、10 至32、39 和40，共28 个，他们的和是574，平方和是14362。
//注意，平方和是指将每个数分别平方后求和。
//请问，在1 到2019 中，所有这样的数的平方和是多少？

#include <iostream>
#include <sstream>
using namespace std;

void i2s(long long x,string & str){
    stringstream ss;
    ss << x;
    ss >> str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    long long ans=0;
    for(long long i=1;i<=2019;i++){
        string s;
        i2s(i, s);
        if(s.find('2')!=string::npos || s.find('0')!=string::npos ||s.find('1')!=string::npos ||s.find('9')!=string::npos){
            ans=ans+i*i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
