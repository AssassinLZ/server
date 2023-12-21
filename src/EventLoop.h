//
// Created by Assassin on 12/21/23.
//

#ifndef SERVER_EVENTLOOP_HPP
#define SERVER_EVENTLOOP_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <vector>

class EventLoop{
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




#endif //SERVER_EVENTLOOP_HPP
