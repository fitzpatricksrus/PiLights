//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_TTHREAD_H
#define PILIGHTS_TTHREAD_H

#include <exception>
#include "pigpio.h"

class TThread {
public:
    TThread();
    virtual ~TThread();

    virtual void start();
    virtual void cancel();
    virtual void kill();
    bool isRunning();
    bool isCanceled();
    void checkCanceled();

    class CanceledException : public std::exception {};

protected:
    virtual void run();
    void sleep(int seconds, int micros);

private:
    bool isThisThread() const;
    void doRun();
    static void *doStart(void* data);

    bool canceled;
    pthread_t* thread;
};

template <class T> class TThreadOf : public TThread {
public:
    typedef void (T::*PtrToMemberFunction)();

    TThreadOf(T* instanceIn, PtrToMemberFunction funcIn);
    virtual void run() override;

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
