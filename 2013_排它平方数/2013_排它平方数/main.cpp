//
//  main.cpp
//  2013_排它平方数
//
//  Created by VachelChen on 2020/1/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//
//
//
//题目标题: 排它平方数
//
//    小明正看着 203879 这个数字发呆。
//
//    原来，203879 * 203879 = 41566646641
//
//    这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
//
//    具有这样特点的6位数还有一个，请你找出它！
//
//    再归纳一下筛选要求：
//    1. 6位正整数
//    2. 每个数位上的数字不同
//    3. 其平方数的每个数位不含原数字的任何组成数位
//
//答案是一个6位的正整数。
//
//请通过浏览器提交答案。
//注意：只提交另一6位数，题中已经给出的这个不要提交。
//注意：不要书写其它的内容（比如：说明性的文字）。
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void i2s(long long x,string &str){
    stringstream ss;
    ss << x;
    ss >> str;
}


int main(){
    int yi,er,san,si,wu,liu;
    for(long long i=123456;i<=987654;i++)
    {
        liu = i%10;
        wu = (i-liu)%100/10;
        si = (i-wu*10-liu)%1000/100;
        san = (i-si*100-wu*10-liu)%10000/1000;
        er = (i-san*1000-si*100-wu*10-liu)%100000/10000;
        yi = (i-er*10000-san*1000-si*100-wu*10-liu)/100000;
        if(liu==wu || liu==si || liu==san || liu==er || liu==yi || wu==si || wu==san || wu==er || wu==yi || si==san || si==er || si==yi || san==er || san==yi || er==yi)
            continue;
        //cout<<i<<" "<<liu<<" "<<wu<<" "<<si<<" "<<san<<" "<<er<<" "<<yi<<endl;
        long long ans;
        ans = i*i;
        //cout<<ans<<endl<<liu+'\0'<<endl;
            string str;
            i2s(ans,str);
        //cout<<str<<endl;
            if(str.find(liu+'0')==string::npos)
                if(str.find(wu+'0')==string::npos)
                    if(str.find(si+'0')==string::npos)
                        if(str.find(san+'0')==string::npos)
                            if(str.find(er+'0')==string::npos)
                                if(str.find(yi+'0')==string::npos){
                                    cout<<i<<endl;
                                }


    }
    return 0;
}
