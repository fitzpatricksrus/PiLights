//
// Created by Dad on 8/28/19.
//

#include "TThread.h"

#include <stdexcept>

TThread::TThread()
: canceled(false), thread(nullptr)
{
}

TThread::~TThread() {
    cancel();
}

void TThread::start() {
    if (!isRunning()) {
        canceled = false;
        thread = gpioStartThread(&TThread::doStart, this);
    } else {
        throw std::logic_error("Can't call start() on a running thread.");
    }
}

void TThread::cancel() {
    canceled = true;
}

void TThread::kill() {
    if (isRunning()) {
        pthread_t* temp = thread;
        thread = nullptr;
        gpioStopThread(temp);
        // if cancel is called from within the thread itself we might never get to here
    }
}

bool TThread::isRunning() {
    return (thread != nullptr);
}

bool TThread::isCanceled() {
    if (isRunning() && canceled) {
        return true;
    } else {
        return false;
    }
}

void TThread::checkCanceled() {
    if (isCanceled() && isThisThread()) {
        throw CanceledException();
    }
}

void TThread::sleep(int seconds, int micros) {
    checkCanceled();
    if (seconds > 0 || micros > 50) {
        gpioSleep(PI_TIME_RELATIVE, seconds, micros);
    } else {
        gpioDelay(micros);
    }
}

void TThread::run() {
    // do something useful
}

bool TThread::isThisThread() const {
    return pthread_self() == *thread;
}

void TThread::doRun() {
    run();
    // we're done so remove the reference to the pthread that's about to exit.
    thread = nullptr;
}

void *TThread::doStart(void* data) {
    static_cast<TThread*>(data)->doRun();
    return nullptr;
}


