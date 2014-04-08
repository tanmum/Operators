//
//  main.cpp
//  Operators
//
//  Created by Tan Bui on 4/8/14.
//  Copyright (c) 2014 tanbui. All rights reserved.
//

#include <iostream>
#include "String.hpp"

int main(int argc, const char * argv[])
{
    String s;
     s = "Hello John!";
     s.prt();
     
     String t;
     t = s;
     t.prt();
     t = 'a';
     t.prt();
     
     String a("All I need ");
     String b("is a few good men...");
     String x;
     x << a << b << "and we'll have lunch" << '!';
     
     x.prt();
    return 0;
}

