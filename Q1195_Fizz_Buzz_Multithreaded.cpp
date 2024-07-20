#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

class FizzBuzz {
private:
    int n;
    int cur_num;
    sem_t sem1, sem2, sem3, sem4;

public:
    FizzBuzz(int n) {
        this->n = n;
        cur_num = 1;
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
        sem_init(&sem3, 0, 0);
        sem_init(&sem4, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 1; i <= n; i++) {
            if(i%3==0 && i%5!=0) {
                while(i != cur_num) sem_wait(&sem1);
                printFizz();
                cur_num++;
                sem_post(&sem2);
                sem_post(&sem3);
                sem_post(&sem4);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 1; i <= n; i++) {
            if(i%3!=0 && i%5==0) {
                while(i!=cur_num) sem_wait(&sem2);
                printBuzz();
                cur_num++;
                sem_post(&sem1);
                sem_post(&sem3);
                sem_post(&sem4);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=1; i<=n; i++){
            if(i%3==0 && i%5==0) {
                while(i!=cur_num) sem_wait(&sem3);
                printFizzBuzz();
                cur_num++;
                sem_post(&sem1);
                sem_post(&sem2);
                sem_post(&sem4);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i++) {
            if(i%3!=0 && i%5!=0) {
                while(i != cur_num) sem_wait(&sem4);
                printNumber(i);
                cur_num++;
                sem_post(&sem1);
                sem_post(&sem2);
                sem_post(&sem3);
            }
        }
    }
};