//
//  main.cpp
//  2014_神奇算式
//
//  Created by VachelChen on 2020/2/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

void i2s(int x,string & str){
    stringstream ss;
    ss << x;
    ss >> str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int ans=0;
    for(int a=1;a<10;a++)
        for(int b=0;b<10;b++){
            if(a!=b){
                for(int c=0;c<10;c++){
                    if(a!=c && b!=c){
                        for(int d=0;d<10;d++){
                            if(a!=d && b!=d && c!=d){
                                string str,as,bs,cs,ds;
                                
                                int a_bcd = a*(b*100+c*10+d);
                                i2s(a_bcd, str);
                                i2s(a, as);i2s(b, bs);i2s(c, cs);i2s(d, ds);
                                if(str.find(as)!=string::npos && str.find(bs)!=string::npos && str.find(cs)!=string::npos && str.find(ds)!=string::npos){
                                    cout<<a<<" "<<b*100+c*10+d<<" "<<a_bcd<<endl;
                                    ans++;
                                }
                                
                                int ab_cd = (a*10+b)*(c*10+d);
                                i2s(ab_cd, str);
                                i2s(a, as);i2s(b, bs);i2s(c, cs);i2s(d, ds);
                                if(str.find(as)!=string::npos && str.find(bs)!=string::npos && str.find(cs)!=string::npos && str.find(ds)!=string::npos){
                                    cout<<a*10+b<<" "<<c*10+d<<" "<<ab_cd<<endl;
                                    ans++;
                                }
                                
                                int abc_d = (a*100+b*10+c)*d;
                                i2s(abc_d, str);
                                i2s(a, as);i2s(b, bs);i2s(c, cs);i2s(d, ds);
                                if(str.find(as)!=string::npos && str.find(bs)!=string::npos && str.find(cs)!=string::npos && str.find(ds)!=string::npos){
                                    cout<<a*100+b*10+c<<" "<<d<<" "<<abc_d<<endl;
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    cout<<ans/2<<endl;
    return 0;
}
