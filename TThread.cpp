//
// Created by Dad on 8/28/19.
//

#include "TThread.h"

TThread::TThread()
: thread(nullptr)
{
}

TThread::~TThread() {
    stop();
}

void TThread::start() {
    stop();
    thread = gpioStartThread(&TThread::doStart, this);
}

void TThread::stop() {
    if (thread) {
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


