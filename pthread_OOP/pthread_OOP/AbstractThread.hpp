//
//  AbstractThread.hpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#ifndef AbstractThread_hpp
#define AbstractThread_hpp

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <time.h>

class AbstractThread{
    
public:
    
    AbstractThread(){}
    virtual ~AbstractThread(){}
    
    bool StartThread_ = false;
    bool IsReady_ = false;
    
    int startThread(); //create the thread
    void signalThread(); //notify the thread to be ready
    void lockThread();
    void unlockThread();
    void waitForSignal();
    void exitThread();

protected:
    
    virtual void* threadEntryFunc() = 0;
    
private:
    
    pthread_t thread_;
    pthread_mutex_t lock_ = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond_ = PTHREAD_COND_INITIALIZER;
    
    static void* internalThreadFunc(void* This){
        ((AbstractThread*)This)->threadEntryFunc();
        return NULL;
    }
    
};

#endif /* AbstractThread_hpp */
