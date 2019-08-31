//
// Created by Dad on 8/30/19.
//

#ifndef PILIGHTS_FIXEDEXECUTIONTIMECODE_H
#define PILIGHTS_FIXEDEXECUTIONTIMECODE_H

/*
 * FixedExecutionTimeCode will sleep the current thread to ensure that the objects lifetime is
 * at least as long as specified in the constructor.
 *
 * void example() {
 *      FixedExecutionTimeCode(1, 0);
 *      //do stuff
 * } // FixedExecutionTimeCode::~FixedExecutionTimeCode() called and code exits 1 second after constructor was called.
 */
class FixedExecutionTimeCode {
public:
    FixedExecutionTimeCode(int seconds, int micros);
    ~FixedExecutionTimeCode();
    void delayNow();

    int delaySeconds;
    int delayMicros;
    int startSeconds;
    int startMicros;
};

#endif //PILIGHTS_FIXEDEXECUTIONTIMECODE_H
