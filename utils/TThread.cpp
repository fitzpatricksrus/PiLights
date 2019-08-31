//
// Created by Dad on 8/28/19.
//

#include "TThread.h"

#include <stdexcept>

TThread::TThread()
: thread(nullptr)
{
}

TThread::~TThread() {
    stop();
}

void TThread::start() {
    if (!isRunning()) {
        thread = gpioStartThread(&TThread::doStart, this);
    } else {
        throw std::logic_error("Can't call start() on a running thread.");
    }
}

void TThread::stop() {
    if (isRunning()) {
        pthread_t* temp = thread;
        thread = nullptr;
        gpioStopThread(temp);
        // if stop is called from within the thread itself we might never get to here
    }
}

bool TThread::isRunning() {
    return (thread != nullptr);
}

void TThread::run() {
    // do something useful
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


