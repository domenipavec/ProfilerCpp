/*
 * profilerCpp.hpp
 * 
 * Copyright 2014 Domen <domen.ipavec@z-v.si>
 * 
 * See LICENSE.
 * 
 */

#ifndef PROFILERCPP_HPP
#define PROFILERCPP_HPP

#include <chrono>
#include <ostream>

namespace ProfilerCpp {
    
    class Timer {
    public:
        Timer();
        void start();
        void stop();
        void clear();
        
        double totalTime;
    private:
        std::chrono::high_resolution_clock::time_point startTime;
    };
    
    void timerStart(const char * const n);
    void timerStop(const char * const n);
    void dumpTimers(std::ostream & s);
    
}

#endif