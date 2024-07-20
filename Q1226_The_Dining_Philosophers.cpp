#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

#include <semaphore.h>

// Solution1: only pick pu forks when both is avaliable
// Solution2: an odd philosophers fist pick left fork and then his right fork, whereas an even philosophers fist right and then left.
// following code is Solution2
class DiningPhilosophers {
private:
    sem_t sem_fork[5];

public:
    DiningPhilosophers() {
        for(int i = 0; i < 5; i++) {
            sem_init(&sem_fork[i], 0, 1);
        }

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l_f = philosopher;
        int r_f = (l_f+1)%5;

        if(philosopher%2 == 1) {
            sem_wait(&sem_fork[l_f]);
            pickLeftFork();
            sem_wait(&sem_fork[r_f]);
            pickLeftFork();
        } else {
            sem_wait(&sem_fork[r_f]);
            pickRightFork();
            sem_wait(&sem_fork[l_f]);
            pickLeftFork();
        }

        eat();

        sem_post(&sem_fork[l_f]);
        putLeftFork();
        sem_post(&sem_fork[r_f]);
        putRightFork();
    }
};