//
//  util.cpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include "util.hpp"

void SaveRawData(void* I, void* Q, int size, const char* DirName, int is_new){
    
    int* Raw_I = (int*) I;
    int* Raw_Q = (int*) Q;
    
    FILE *fp;
    
    time_t time_p = time(NULL);
    struct tm *tm_p = gmtime(&time_p);
    
    string fname = "SaveData_" + std::to_string(tm_p->tm_year) + "_" + std::to_string(tm_p->tm_mon) + "_" + std::to_string(tm_p->tm_yday);
    
    
//    if((fp = fopen("SaveData", "r")) == NULL){
//        std::cout << "Unable to open the file" << std::endl;
//        return;
//    }
    
    for(int i = 0; i<size; i++){
        std::cout << Raw_I[i] << "," << Raw_Q[i] << std::endl;
    }
    
    
}
