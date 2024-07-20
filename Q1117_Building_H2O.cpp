#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

class H2O {
private:
    sem_t sem1, sem2;
    int cur_num;

public:
    H2O() {
        sem_init(&sem1, 0, 1);
        sem_init(&sem2, 0, 1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&sem1);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cur_num++;
        if(cur_num%2 == 0) sem_post(&sem2);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&sem2);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&sem1);
        sem_post(&sem1);
    }
};

H2O *obj;

void *thread1(void *args){
    obj->hydrogen([](){ printf("H"); });
    return NULL;
}
void *thread2(void *args){
    obj->oxygen([](){ printf("O"); });
    return NULL;
}

void release(char val){
    pthread_t thid;
    if(val == 'H') pthread_create(&thid, NULL, thread1, NULL);
    else pthread_create(&thid, NULL, thread2, NULL);
}

int main(int argc, char *argv[]){
    char *input = argv[1];
    int input_len = strlen(input);
    obj = new H2O();

    for(int i = 0; i < input_len; i++) {
        release(input[i]);
    }

    sleep(1);
    return 0;
}