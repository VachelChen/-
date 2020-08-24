//
//  main.cpp
//  BJFU_258
//
//  Created by VachelChen on 2020/8/22.
//  Copyright © 2020 VachelChen. All rights reserved.
//
#include<iostream>
#include<cstring>
using namespace std;
void F(char c[],int n,int m)
{
    char t;
    if(m<n/2)
    {
        t=c[m];
        c[m]=c[n-m-1];
        c[n-m-1]=t;
        F(c,n,m+1);
    }
    else
        cout<<c<<endl;
}
int main()
{
    char c[100];
    while(cin>>c&&c[0]!='0')
    {
        int n=(int)strlen(c);
        F(c,n,0);
    }
    return 0;
}
