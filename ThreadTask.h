#ifndef THREADTASK_H
#define THREADTASK_H

#include <pthread.h>
#include <unistd.h>

class ThreadTask{
    public:
        ThreadTask();
        virtual ~ThreadTask();
        pthread_t thread;
        bool startThread();
        void joinThread();

    protected:
        virtual void doOnThread() = 0;

    private:


        static void *doThread(void *This);
};

#endif
