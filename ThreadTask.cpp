#include "ThreadTask.h"

ThreadTask::ThreadTask(){}

ThreadTask::~ThreadTask(){}

bool ThreadTask::startThread(){
    return (pthread_create(&thread, NULL, doThread, this) == 0);
}

void ThreadTask::joinThread(){
    (void) pthread_join(thread, NULL);
}

void *ThreadTask::doThread(void *This){
    ((ThreadTask *)This)->doOnThread();
    return NULL;
}
