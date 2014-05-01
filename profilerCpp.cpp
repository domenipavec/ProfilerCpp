/*
 * profilerCpp.cpp
 * 
 * Copyright 2014 Domen <domen.ipavec@z-v.si>
 * 
 * See LICENSE.
 * 
 */

#include "profilerCpp.hpp"

#include <map>

namespace ProfilerCpp {
    
    Timer::Timer()
            : totalTime(0), startTime(std::chrono::high_resolution_clock::now()) {
    }
    
    void Timer::start() {
        startTime = std::chrono::high_resolution_clock::now();
    }
    
    void Timer::stop() {
        totalTime += std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - startTime).count();
    }
    
    void Timer::clear() {
        totalTime = 0;
    }
    
    std::map<const char *, Timer> timerMap;
    
    void timerStart(const char * const n) {
        std::map<const char*, Timer>::iterator it = timerMap.find(n);
        if (it == timerMap.end()) {
            it = timerMap.insert(std::pair<const char *, Timer>(n,Timer())).first;
        }
        it->second.start();
    }
    
    void timerStop(const char * const n) {
        timerMap[n].stop();
    }
    
    void dumpTimers(std::ostream & s) {
        for (std::map<const char*, Timer>::iterator it = timerMap.begin(); it != timerMap.end(); ++it) {
            s << "Timer \"" << it->first << "\" took " << it->second.totalTime << " seconds." << std::endl;
        }
    }
    
}
