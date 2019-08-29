//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_TTHREAD_H
#define PILIGHTS_TTHREAD_H

#include "pigpio.h"

class TThread {
public:
    TThread();
    virtual ~TThread();

    virtual void start();
    virtual void stop();
    virtual bool isRunning();

protected:
    virtual void run();

private:
    void doRun();
    static void *doStart(void* data);

    pthread_t* thread;
};

template <class T> class TThreadOf : public TThread {
public:
    typedef void (T::*PtrToMemberFunction)();

    TThreadOf(T* instanceIn, PtrToMemberFunction funcIn);
    virtual void run();

private:
    T* instance;
    PtrToMemberFunction memberFunction;
};

template <class T> TThreadOf<T>::TThreadOf(T *instanceIn, TThreadOf<T>::PtrToMemberFunction funcIn)
: TThread(), instance(instanceIn), memberFunction(funcIn) {}

template <class T> void TThreadOf<T>::run() {
    (instance->*memberFunction)();
}

#endif //PILIGHTS_TTHREAD_H
