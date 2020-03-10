//
//  main.cpp
//  codeup_大数a+b
//
//  Created by VachelChen on 2020/3/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

struct bign{
  int d[1000];
  int len;
  //因为结构体中有数组，定义的时候需要初始化一下。
  bign(){
    memset(d,0,sizeof(d));
    len = 0;
  }
};

bign change(string str){
  bign a;
  a.len = str.size();
  for(int i=0;i<a.len;i++)
    a.d[i] = str[a.len-i-1] - '0';
  return a;
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

//必须要a>b
bign sub(bign a,bign b){
  bign c;
  for(int i=0;i<max(a.len,b.len);i++){
    if(a.d[i]<b.d[i]){
      a.d[i+1]--;
      a.d[i] += 10;
    }
    c.d[c.len++] = a.d[i] - b.d[i];
  }
  while(c.len >=2 && c.d[c.len-1] == 0)
  {c.len--;}

  return c;
}

int main(int argc, const char * argv[]) {
    string x,y;
    string ans;
    while (cin >> x >> y) {
        bign a,b,ans;
        a = change(x);
        b = change(y);
        ans = sub(a, b);
        for(int i=ans.len-1;i>=0;i--){
            cout<<ans.d[i];
        }
        
        cout<<endl;
    }
    return 0;
}
