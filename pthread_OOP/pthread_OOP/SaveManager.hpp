//
//  SaveManager.hpp
//  pthread_OOP
//
//  Created by 邵国亮 on 15/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#ifndef SaveManager_hpp
#define SaveManager_hpp

#include <stdio.h>
#include <time.h>

#include "AbstractThread.hpp"
#include "util.hpp"


class SaveManager : public AbstractThread{
    
public:
    
    SaveManager(int Save_Per_length, int N_buffer, int buffer_size);
    ~SaveManager();
    
    void record(int I, int Q);
    
protected:
    
    void* threadEntryFunc() override;
    
private:
    int Save_Per_length_, N_buffer_, buffer_size_;
    
    int **Raw_I_, **Raw_Q_;
    int curr_index_;
    int curr_buf_;
    int save_buf_;
    int total_num_count_;
    
    
};

#endif /* SaveManager_hpp */
