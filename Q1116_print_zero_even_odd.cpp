#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    int cur_num;
    sem_t sem1, sem2, sem3;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cur_num = 0;
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
        sem_init(&sem3, 0, 1);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 0; i < n; i++) {
            sem_wait(&sem3);
            printNumber(0);
            cur_num++;

            if(cur_num%2 == 0) sem_post(&sem1);
            else sem_post(&sem2);
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 0; i < n/2; i++) {
            sem_wait(&sem1);
            printNumber(cur_num);
            sem_post(&sem3);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 0; i < n/2 + n%2; i++) {
            sem_wait(&sem2);
            printNumber(cur_num);
            sem_post(&sem3);
        }
    }
};
ZeroEvenOdd *obj;
void *thread1(void *arg){
    obj->zero([](int num){ printf("%d", num); });
}
void *thread2(void *arg){
    obj->even([](int num){ printf("%d", num); });
}
void *thread3(void *arg){
    obj->odd([](int num){ printf("%d", num); });
}

int main(int argc, char *argv[]) {
    obj = new ZeroEvenOdd(atoi(argv[1]));
    pthread_t thid1, thid2, thid3;

    pthread_create(&thid1, NULL, thread1, NULL);
    pthread_create(&thid2, NULL, thread2, NULL);
    pthread_create(&thid3, NULL, thread3, NULL);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    pthread_join(thid3, NULL);

    return 0;
}