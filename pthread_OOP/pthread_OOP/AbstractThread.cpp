//
//  AbstractThread.cpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include "AbstractThread.hpp"


int AbstractThread::startThread(){
    StartThread_ = true;
           
    int perr = pthread_create(&thread_, nullptr, internalThreadFunc,this);
    perr = pthread_detach(thread_); //separate the child thread from the main thread
    return perr;
}

void AbstractThread::signalThread(){
    IsReady_ = true;
    pthread_cond_signal(&cond_);
}

void AbstractThread::lockThread(){
    pthread_mutex_lock(&lock_);
}

void AbstractThread::unlockThread(){
    pthread_mutex_unlock(&lock_);
}

void AbstractThread::waitForSignal(){
    pthread_cond_wait(&cond_, &lock_); //release the lock, and wait for the signal
}

void AbstractThread::exitThread(){
    pthread_exit(NULL);
}




