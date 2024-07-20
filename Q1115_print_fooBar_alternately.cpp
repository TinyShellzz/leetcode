#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t sem1, sem2;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&sem1, 0, 1);
        sem_init(&sem2, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem1);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&sem2);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem2);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&sem1);
        }
    }
};
FooBar *foobar;

void *thread1(void *arg){
    foobar->foo([](){ printf("foo"); });
}

void *thread2(void *arg){
    foobar->bar([](){ printf("bar"); });
}

int main(int argc, char *argv[]) {
    foobar = new FooBar(atoi(argv[1]));
    pthread_t thid1, thid2;

    pthread_create(&thid1, NULL, thread1, NULL);
    pthread_create(&thid2, NULL, thread2, NULL);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    cout << endl;
    return 0;
}