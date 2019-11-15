//
//  SaveManager.cpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include "SaveManager.hpp"

SaveManager::SaveManager(int Save_Per_length, int N_buffer, int buffer_size) : Save_Per_length_(Save_Per_length), N_buffer_(N_buffer), buffer_size_(buffer_size){
    
    //malloc saving buffer
    Raw_I_ = (int**) malloc(sizeof(int*) * N_buffer);
    Raw_Q_ = (int**) malloc(sizeof(int*) * N_buffer);
    
    for(int i = 0; i<N_buffer_; i++){
        Raw_I_[i] = (int*) malloc(sizeof(int) * buffer_size_);
        Raw_Q_[i] = (int*) malloc(sizeof(int) * buffer_size_);
    }
    
    save_buf_ = -1;
    curr_buf_ = 0;
    curr_index_ = 0;
    total_num_count_ = 0;
    
    
}


SaveManager::~SaveManager(){
    
    //free the buffer first
    for(int i = 0; i<N_buffer_; i++){
        free(Raw_I_[i]);
        free(Raw_Q_[i]);
    }
    
    //free pointer next
    free(Raw_I_);
    free(Raw_Q_);
}


void* SaveManager::threadEntryFunc(){
    
    //create a non-stop thread
    while(this->StartThread_){
        this->lockThread();
        
        while(!this->IsReady_){
            this->waitForSignal();
        }
        
        if(!this->StartThread_){
            break;
        }
        
        SaveRawData(Raw_I_[save_buf_], Raw_Q_[save_buf_], this->Save_Per_length_, NULL, 0);
        
        IsReady_ = false;
        this->unlockThread();
    }
    
    this->exitThread();
    return NULL;
}


void SaveManager::record(volatile int I, volatile int Q){
    Raw_I_[curr_buf_][curr_index_] = I;
    Raw_Q_[curr_buf_][curr_index_] = Q;
    
    curr_index_++;
    total_num_count_++;
    
    if(curr_index_ >= Save_Per_length_) {
        lockThread();
        std::cout << "save buf:" << curr_buf_ << std::endl;
        save_buf_ = curr_buf_;
        this->signalThread();
        curr_index_ = 0;
        
        if(curr_buf_ >= N_buffer_-1) curr_buf_ = 0;
        else curr_buf_++;
        
        std::cout << "curr buf:" << curr_buf_ << std::endl;
        unlockThread();
    }
}


