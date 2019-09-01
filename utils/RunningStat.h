//
// Created by Dad on 8/31/19.
//

#ifndef PILIGHTS_RUNNINGSTAT_H
#define PILIGHTS_RUNNINGSTAT_H

/*
        RunningStat rs;

        rs.Push(17.0);
        rs.Push(19.0);
        rs.push(24.0);

        double mean = rs.mean();
        double variance = rs.variance();
        double stdev = rs.standardDeviation();
 */
class RunningStat {
public:
    RunningStat();
    void clear();
    void push(double x);
    int numDataValues() const;
    double mean() const;
    double variance() const;
    double standardDeviation() const;
    double standardError() const;
    double marginOfError() const;
    double confidenceIntervalHigh() const;
    double confidenceIntervalLow() const;
    double coefficientOfVariance() const;

private:
    int sampleSize;
    double m_oldM, m_newM, m_oldS, m_newS;
};

#endif //PILIGHTS_RUNNINGSTAT_H
