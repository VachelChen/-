//
//  main.cpp
//  2013_颠倒的价牌
//
//  Created by VachelChen on 2020/1/31.
//  Copyright © 2020 VachelChen. All rights reserved.
//
//        标题: 颠倒的价牌
//
//
//            小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。
//
//            其标价都是4位数字（即千元不等）。
//
//            小李为了标价清晰、方便，使用了预制的类似数码管的标价签，只要用颜色笔涂数字就可以了（参见p1.jpg）。
//
//            这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，比如：1958 倒着挂就是：8561，差了几千元啊!!
//
//            当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。
//
//            有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!
//
//            庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。
//
//            请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？
//
//
//        答案是一个4位的整数，请通过浏览器直接提交该数字。
//        注意：不要提交解答过程，或其它辅助说明类的内容。
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
     //insert code here...
    int x=0,y=0,xf=0,yf=0;
    int x11,x22,x33,x44;
    int y11,y22,y33,y44;
    for(int x1=1;x1<=9;x1++){
        if(x1==3 || x1 ==4 || x1 == 7)
            continue;
        for(int x2=0;x2<=9;x2++){
            if(x2==3 || x2 ==4 || x2 == 7)
                continue;
            for(int x3=0;x3<=9;x3++){
                if(x3==3 || x3 ==4 || x3== 7)
                continue;
                for(int x4=1;x4<=9;x4++){
                    
                    if(x4==3 || x4 ==4 || x4 == 7)
                    continue;
                    
                    x=x1+x2*10+x3*100+x4*1000;
                    //cout<<x<<" x"<<endl;
                    if(x1 == 6) x11=9;   else if(x1 == 9) x11=6;    else x11=x1;
                    if(x2 == 6) x22=9;   else if(x2 == 9) x22=6;    else x22=x2;
                    if(x3 == 6) x33=9;   else if(x3 == 9) x33=6;    else x33=x3;
                    if(x4 == 6) x44=9;   else if(x4 == 9) x44=6;    else x44=x4;
                    xf=x44+x33*10+x22*100+x11*1000;
                    //out<<xf<<" xf"<<endl;
                    if(x-xf>=200 && x-xf<300){
                        //cout<<x<<" xf: "<<xf<<"   "<<xf-x<<endl;

                        for(int y1=1;y1<=9;y1++){
                            if(y1==3 || y1 ==4 || y1 == 7)
                            continue;
                            for(int y2=0;y2<=9;y2++){
                                if(y2==3 || y2 ==4 || y2 == 7)
                                continue;
                                for(int y3=0;y3<=9;y3++){
                                    if(y3==3 || y3 ==4 || y3 == 7)
                                    continue;
                                    for(int y4=1;y4<=9;y4++){
                                        if(y4==3 || y4 ==4 || y4 == 7)
                                        continue;
                                        y=y1+y2*10+y3*100+y4*1000;
                                        //cout<<"y:"<<y<<endl;
                                        if(y1 == 6) y11=9;   else if(y1 == 9) y11=6;    else y11=y1;
                                        if(y2 == 6) y22=9;   else if(y2 == 9) y22=6;    else y22=y2;
                                        if(y3 == 6) y33=9;   else if(y3 == 9) y33=6;    else y33=y3;
                                        if(y4 == 6) y44=9;   else if(y4 == 9) y44=6;    else y44=y4;
                                        yf=y44+y33*10+y22*100+y11*1000;
                                        
                                        //cout<<y<<" yf: "<<yf<<endl;
                                        
                                        if(yf-y>=800 && yf-y<900){
                                            //cout<<y<<" yf: "<<xf<<"   "<<xf-x<<endl;
                                            if(xf-x+yf-y == 558){
                                                cout<<x<<" "<<y<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    

    return 0;
}
