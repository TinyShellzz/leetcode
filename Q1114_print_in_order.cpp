#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

class Foo {
public:
    sem_t sem1, sem2;

    Foo() {
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
    }

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&sem1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem1);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&sem2);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem2);

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

Foo foo = Foo();

void *thread1(void *arg) {
    foo.first([](){ printf("first"); });
}
void *thread2(void *arg) {
    foo.second([](){ printf("second"); });
}
void *thread3(void *arg) {
    foo.third([](){ printf("third"); });
}

int main(){
    pthread_t thid1, thid2, thid3;
    pthread_create(&thid2, NULL, thread2, NULL);
    pthread_create(&thid1, NULL, thread1, NULL);
    pthread_create(&thid3, NULL, thread3, NULL);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    pthread_join(thid3, NULL);
    cout << endl;
    return 0;
}