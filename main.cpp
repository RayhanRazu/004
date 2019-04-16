//
//  main.cpp
//  MyList
//
//  Created by Yevon Zhang on 17/4/10.
//  Copyright (c) 2017年 Yevon Zhang. All rights reserved.
//

#include <iostream>
#include "Complex.h"
#include "Rational.h"
#include "Irrational.h"
#include "MyList.h"

using namespace std;

int main(int argc, const char * argv[]) {
  
    MyList<int> a(4,2);
    MyList<std::string> b(3,"hello");
    MyList<Complex> c(5,Complex(5,5));
    
    Rational r(5,8);
    Irrational ir(53.33333333);
    Complex cx(49.3,7.0);
    
    MyList<int> aa;
    cout<<aa<<endl;
    
    int preCa = aa.getCapacity();
    for (int i = 0; i < 100; ++i){
        aa.push_back(i+1);
        if(aa.getCapacity() > preCa){
            cout<<aa<<endl;
            cout<<aa+a<<endl;
            cout<<aa-a<<endl;
            preCa = aa.getCapacity();
        }
    }
    
    MyList<Number*> d;
    d.push_back(&r);
    d.push_back(&ir);
    d.push_back(&cx);
    
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    //cout<<d<<endl;
    
    c.reserve(6);
    cout<<c<<endl;
    c.push_back(Complex(2.3,5.009));
    cout<<c<<endl;
    c.push_back(Complex(-8,-75.009));
    cout<<c<<endl;
    
    
    cout<< d.size();
    cout<< "("<<d.getCapacity()<<"):";
    for (int i = 0; i < d.size(); ++i)
        cout<< d[i]->toString() << " ";
    cout<<endl;
    
    try{
        cout<<d[d.size()+1]<<endl;
        
    }catch(My_Out_of_Range_Exception &ex)
    {
        cout<<"We know how to deal with the errors"<<endl;
    }
    
    return 0;
}
