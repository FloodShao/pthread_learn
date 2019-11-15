//
//  main.c
//  pthread
//
//  Created by 邵国亮 on 14/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

//
//  pthread1.cpp
//  pthread_learning
//
//  Created by 邵国亮 on 14/11/19.
//

#include <stdio.h>
#include <stdlib.h> //C 标准库文件
#include <unistd.h> //对POSIX操作系统API进行访问的头文件
#include <pthread.h>


void* xc(void* arg){
    
    char* c = (char*) arg;
    printf("参数%s\n", c);
    int i = 0;
    for(; i<10; i++){
        printf("循环%d\n", i);
        if(i == 5){
            pthread_exit(100);
        }
    }
    
    return 102;
}


int main(){
    
    pthread_t tid;
    pthread_create(& tid, NULL, xc, "thread!");
    
    void* status;
    pthread_join(tid, &status);
    printf("return %d\n", (int) status);
    
    return 0;
    
}



