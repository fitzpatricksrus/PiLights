//
// Created by Dad on 8/31/19.
//

#include "RunningStat.h"
#include <cmath>

// confidence interval mean +/- z * standard deviation/sqrt(number of samples)
/*
 * z is
80%	1.282
85%	1.440
90%	1.645
95%	1.960
99%	2.576
99.5%	2.807
99.9%	3.291

 */

RunningStat::RunningStat()
: sampleSize(0)
{
}

void RunningStat::clear() {
    sampleSize = 0;
}

void RunningStat::push(double x) {
    sampleSize++;

    // See Knuth TAOCP vol 2, 3rd edition, page 232
    if (sampleSize == 1) {
        m_oldM = m_newM = x;
        m_oldS = 0.0;
    } else {
        m_newM = m_oldM + (x - m_oldM) / sampleSize;
        m_newS = m_oldS + (x - m_oldM)*(x - m_newM);

        // set up for next iteration
        m_oldM = m_newM;
        m_oldS = m_newS;
    }
}

int RunningStat::numDataValues() const {
    return sampleSize;
}

double RunningStat::mean() const {
    return (sampleSize > 0) ? m_newM : 0.0;
}

double RunningStat::variance() const {
    return ((sampleSize > 1) ? m_newS / (sampleSize - 1) : 0.0 );
}

double RunningStat::standardDeviation() const {
    return sqrt(variance() );
}

double RunningStat::standardError() const {
    return standardDeviation() / sqrt(numDataValues());
}

double RunningStat::marginOfError() const {
    return standardError() * 2.0d;
}

double RunningStat::confidenceIntervalHigh() const {
    return mean() + marginOfError();
}

double RunningStat::confidenceIntervalLow() const {
    return mean() - marginOfError();
}



double RunningStat::coefficientOfVariance() const {
    return standardDeviation() / mean();
}
