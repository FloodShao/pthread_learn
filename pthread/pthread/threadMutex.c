//
//  threadMutex.c
//  pthread
//
//  Created by 邵国亮 on 14/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int i = 0; // 共享资源

pthread_mutex_t lock;

void* thr_fun(void* arg){
    //add lock
    pthread_mutex_lock(&lock);
    
    char* no = (char*) arg;
    for(; i<5; i++){
        printf("%s thread, i:%d\n", no, i);
        sleep(1);
    }
    i = 0;
    //remove the lock
    pthread_mutex_unlock(&lock);
    
    return 100;
}

int main(){
    
    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, thr_fun, "NO1");
    pthread_create(&tid2, NULL, thr_fun, "NO2");
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}


