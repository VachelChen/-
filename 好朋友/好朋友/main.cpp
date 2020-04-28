//
//  main.cpp
//  PAT_A1034
//
//  Created by VachelChen on 2020/3/30.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;

const int maxn = 1000001;

struct bign{
  int d[10000];
  long long len;
  //因为结构体中有数组，定义的时候需要初始化一下。
  bign(){
    memset(d,0,sizeof(d));
    len = 0;
  }
};

bign multi(bign a,int b){
    bign c;
    int carry = 0;
    for(int i=0;i<a.len;i++){
        int temp = a.d[i]*b +carry;
        c.d[c.len++] = temp % 10;
        carry = temp/10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry %10;
        carry /=10;
    }
    return c;
}

bign add(bign a,bign b){
  bign c;
  int carry = 0;
  for(int i=0;i<max(a.len,b.len);i++){
    int temp = a.d[i] + b.d[i] + carry;
    c.d[c.len++] = temp%10;
    carry = temp/10;
  }
  if(carry!=0){
    c.d[c.len++] = carry;
  }
  return c;
}

bign change(char str[]){
    bign a;
    a.len = (int)strlen(str);
    for(int i =0;i<a.len;i++){
        a.d[i] = str[a.len - i-1]-'0';
    }
    return a;
}

void print(bign a){
    for(int i=a.len-1;i>=0;i--){
        cout<<a.d[i];
    }
}

string l2s(int x){
    string str;
    stringstream ss;
    ss << x;
    ss >> str;
    return str;
}

int s2l(string s){
    int x;
    stringstream ss;
    ss << s;
    ss >> x;
    return x;
}

int chen[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
bool isleayear(int year)
{
    return (year%4==0&&year%100!=0)||(year%400==0);
}
 
int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    a = a.substr(0,4)+a.substr(5,2)+a.substr(8,2);
    b = b.substr(0,2)+b.substr(3,2)+b.substr(6,2);
    c = c.substr(0,4)+c.substr(5,2)+c.substr(8,2);
    d = d.substr(0,2)+d.substr(3,2)+d.substr(6,2);
    int time1,y1,m1,d1;
    int time2,y2,m2,d2;
    time1 = s2l(a);
    time2 = s2l(c);
    
        if(time1>time2)
        {
            int temp=time1;
            time1=time2;
            time2=temp;
        }
        long long n=0;
        d1=time1%100;m1=time1/100%100;y1=time1/10000;
        d2=time2%100;m2=time2/100%100;y2=time2/10000;
        while(d1<d2||m1<m2||y1<y2)
        {
            d1++;
            if(d1==chen[m1][isleayear(y1)]+1)
            {
                d1=1;
                m1++;
            }
            if(m1==13)
            {
                m1=1;
                y1++;
            }
            n++;
        }
    //天数 n;
    int miao1,s1,f1,mi1;
    int miao2,s2,f2,mi2;
    bool flag = false;
    miao1 = s2l(b);
    miao2 = s2l(d);
    
        if(miao1>miao2)
        {
            int temp=miao1;
            miao1=miao2;
            miao2=temp;
            flag = true;
        }
        long long m=0;
        mi1=miao1%100;f1=miao1/100%100;s1=miao1/10000;
        mi2=miao2%100;f2=miao2/100%100;s2=miao2/10000;
        while(mi1<mi2||f1<f2||s1<s2)
        {
            mi1++;
            if(mi1==60)
            {
                mi1=0;
                f1++;
            }
            if(f1==60)
            {
                f1=0;
                s1++;
            }
            m++;
        }
    //秒数 m；
    if(flag){
        n = n-1;
        m = 86400 - m;
    }
    m = m*1000;
    char allm[maxn],mmiao[maxn];
    snprintf(allm, sizeof(allm), "%lld", n);
    snprintf(mmiao, sizeof(mmiao), "%lld", m);
    bign x1 = change(allm);
    bign x2 = change(mmiao);
    bign tianmiao = multi(x1, 86400000);
    bign y = add(tianmiao,x2);
    print(y);
    cout<<endl;
    return 0;
}

