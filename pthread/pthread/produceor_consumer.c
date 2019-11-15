//
//  produceor_consumer.c
//  pthread
//
//  Created by 邵国亮 on 14/11/19.
//  Copyright © 2019 邵国亮. All rights reserved.
//

#include "produceor_consumer.h"

pthread_t tid[CONSUMER_NUM + PRODUCER_NUM]; //create the thread number

int products = 0; //the number of products available

pthread_mutex_t lock;
pthread_cond_t hasProduct;

void* producer_func(void* arg){
    
    int no = (int) arg;
    
    while(1){
        pthread_mutex_lock(&lock);
        
        //produce the product
        
        if(products > 10){
            sleep(1);
            pthread_mutex_unlock(&lock);
        } else{
            products++;
            printf("Producor %d, produce produce product %d\n", no, products);
            
            //notify the consumer;
            pthread_cond_signal(&hasProduct);
            printf("producer %d send signal.\n", no);
            pthread_mutex_unlock(&lock);
            sleep(1); //unlock the lock by sleep the thread
        }
    }
    
    return 0;
}


void* consumer_func(void* arg){
    
    int no = (int) arg;
    
    while(1){
        pthread_mutex_lock(&lock);
        
        while(products == 0){
            //busy waiting
            printf("consumer %d is waiting.\n", no);
            pthread_cond_wait(&hasProduct, &lock); //in the meantime release the lock
        }
        
        products--;
        printf("Consumer %d consume %d products\n", no, 1);
        pthread_mutex_unlock(&lock);
    }
    
    return 0;
    
}

int main(){
    
    //initiate the lock and the condition
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&hasProduct, NULL);
    printf("Init the mutex and cond\n");
    
    int i = 0;
    for(; i<CONSUMER_NUM; i++){
        pthread_create(&tid[i], NULL, consumer_func, (void*)i);
    }
    for(; i<CONSUMER_NUM + PRODUCER_NUM; i++){
        pthread_create(&tid[i], NULL, producer_func, (void*)(i-CONSUMER_NUM));
    }
    
    sleep(10);
    
    for(int i = 0; i<CONSUMER_NUM + PRODUCER_NUM; i++){
        pthread_join(tid[i], NULL);
    }
    
    pthread_cond_destroy(&hasProduct);
    pthread_mutex_destroy(&lock);
    
    
    return 0;
    
}
