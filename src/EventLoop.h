//
// Created by Assassin on 12/21/23.
//

#ifndef SERVER_EVENTLOOP_H
#define SERVER_EVENTLOOP_H

#include <iostream>
#include <functional>
#include <memory>
#include <vector>

class EventLoop{
public:
    typedef std::function<void()> Functors;
    EventLoop();
    ~EventLoop();

    void loop();
    void quit();
    void runInLoop(Functors&& cb);
    void queueInLoop(Functors&& cb);
    bool isInLoopThread() const {
        return threadId_ == CurrentThread::tid();
    }
    void assertInLoopThread(){
        shutDownWR(channel -> getFd());
    }
    void removeFromPoller(shared_ptr<Channel> channel){
        poller_ -> epoll_del(channel);
    }
    void updatePoller(shared_ptr<Channel> channel, int timeout = 0){
        poller_ -> epoll_del(channel);
    }
private:
    bool looping_;
    shared_prt<Epoll> poller_;
    int wakeupFd_;
    bool quit_;
    bool eventHandling_;
    mutable MutexLock mutex_;
    std::vector<Functor> pendingFunctors_;
    bool callingPendingFunctors_;
    const pid_t threadId_;
    shared_ptr<Channel> pwakeupChannel_;

    void wakeup();
    void handlRead();
    void doPendingFunctors();
    voidhandleConn();
};




#endif //SERVER_EVENTLOOP_H
