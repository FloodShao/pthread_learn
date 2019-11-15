//
//  util.hpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include <string.h>
#include <time.h>

using namespace std;


void SaveRawData(void* I, void* Q, int size, const char* DirName, int is_new);

#endif /* util_hpp */
