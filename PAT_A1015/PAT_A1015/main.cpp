//
//  main.cpp
//  PAT_A1015
//
//  Created by VachelChen on 2020/5/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 10001;
int temp[maxn];

string i2s(int x){
    string str;
    stringstream ss;
    ss << x;
    ss >> str;
    return str;
}

int s2i(string str){
    int x;
    stringstream ss;
    ss << str;
    ss >> x;
    return x;
}

bool judge(int x){
    for (int i=2; i<=sqrt(x); i++) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

int tenton(int n,int d){
    int i=0;
    while (n>=d) {
        temp[i] = n%d;
        n /= d;
        i++;
    }
    temp[i] = n;
    int j = i,index=0,newn=0;
    while (j >= 0) {
        newn += temp[j]*pow(d, index);
        j--;
        index++;
    }
    return newn;
}

int main(int argc, const char * argv[]) {
   
    int n,d,newn;
    scanf("%d",&n);
    while (n>=2) {
        scanf("%d",&d);
        memset(temp, 0, sizeof(temp));
        if(!judge(n) || n==1)   cout<<"No"<<endl;
        else{
            newn = tenton(n,d);
            if (!judge(newn) || newn==1) {
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
        scanf("%d",&n);
    }
    return 0;
}
