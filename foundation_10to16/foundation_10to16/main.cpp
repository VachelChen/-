//
//  main.cpp
//  foundation_16to8
//
//  Created by VachelChen on 2020/2/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string l2s(long long x){
    string str;
    stringstream ss;
    ss << x;
    ss >> str;
    return str;
}



long long ten22(long long x){
    if(x<2)
        return x;
    else
        return ten22(x/2)*10+(x%2);
}

int main(int argc, const char * argv[]) {
    long long a;
    cin>>a;
    string two = l2s(ten22(a));
    
    reverse(two.begin(),two.end());
    int y = two.size()%4;
    if(y != 0){
        for(int i=0;i<4-y;i++)
            two += '0';
    }
    reverse(two.begin(),two.end());
    long long four = (int)two.size()/4;
    
    string ans="";
    
    for(long long i=0;i<four;i++){
        string x = two.substr(i*4,4);
        if(x == "0000") ans+='0';
        else if(x == "0001") ans+='1';
        else if(x == "0010") ans+='2';
        else if(x == "0011") ans+='3';
        else if(x == "0100") ans+='4';
        else if(x == "0101") ans+='5';
        else if(x == "0110") ans+='6';
        else if(x == "0111") ans+='7';
        else if(x == "1000") ans+='8';
        else if(x == "1001") ans+='9';
        else if(x == "1010") ans+='A';
        else if(x == "1011") ans+='B';
        else if(x == "1100") ans+='C';
        else if(x == "1101") ans+='D';
        else if(x == "1110") ans+='E';
        else if(x == "1111") ans+='F';
    }
    cout<<ans<<endl;
    return 0;
}
