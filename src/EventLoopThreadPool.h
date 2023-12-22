//
// Created by Assassin on 12/21/23.
//

#ifndef SERVER_EVENTLOOPTHREADPOOL_H
#define SERVER_EVENTLOOPTHREADPOOL_H


#include <memory>
#include <vector>
#include "EventLoopThread.h"
#include "base/Logging.h"
#include "base/noncopyable.h"

class EventLoopThreadPoll : noncopyable {
public:
    EventLoopThreadPoll(EventLoop* baseeLoop, int numThreads);
    ~EventLoopThreadPoll(){
        LOG << "~EventLoopThreadPoll()";
    }
    void start()
    EventLoop* getNextLoop();
    
private:
    EventLoop* baseLoop_;
    bool started_;
    int numThreads_;
    int next_;
    std::vector<std::shared_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};


#endif //SERVER_EVENTLOOPTHREADPOOL_H
