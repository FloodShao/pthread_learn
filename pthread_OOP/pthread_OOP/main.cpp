//
//  main.cpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include <iostream>
#include "util.hpp"
#include "SaveManager.hpp"

#include <vector>
#include <time.h>


static int max_length = 50;
static int num_buf = 2;
static int save_per_length = 40;

int main(int argc, const char * argv[]) {
    
    time_t timep = time(NULL);
    struct tm *tm_p = gmtime(&timep);
    
    SaveManager *SM;
    SM = new SaveManager(save_per_length, num_buf, max_length);
    
    vector<int> I(100);
    vector<int> Q(100);
    
    SM->startThread();
    
    for(int i = 0; i<120; i++){
        SM->record(i, i+1);
        sleep(0.001);
    }
    
    pause();
    return 0;
}
