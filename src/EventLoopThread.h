//
// Created by Assassin on 12/21/23.
//

#ifndef SERVER_EVENTLOOPTHREAD_H
#define SERVER_EVENTLOOPTHREAD_H


#include "EventLoop.h"
#include "base/Condition.h"
#include "base/MutexLock.h"
#include "base/Thread.h"
#include "base/noncopyable.h"

class EventLoopThread : noncopyable{
public:
    EventLoopThread();
    ~EventLoopThread();
    EventLoop* startLoop();

private:
    void threadFunc();
    Eventloop* loop_;
    bool exiting_;
    Thread thread_;
    Mutexlock mutex_;
    Condition cond_;
};



#endif //SERVER_EVENTLOOPTHREAD_H
