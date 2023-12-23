//
// Created by Assassin on 12/21/23.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <memory>
#include "Channel.h"
#include "EventLoop.h"
#include "EventLoopThreadPool.h"

class Server{
public:
    Server(EventLoop* loop, int threadNum, int port);
    ~Server(){}
    EventLoop* getLoop() const { return loop_; }
    void start();
    void handNewConn();
    void handThisConn() { loop_ -> updatePoller(acceptChannel_); }

private:
    EventLoop* loop_;
    int threadNum_;
    std::unique_ptr<EventLoopThreadPool> eventLoopThreadPool_;
    bool started_;
    std::shared_ptr<Channel> acceptChannel_;
    int port_;
    int listendFd_;
    static const int MAXFDS = 100000;
};

#endif //SERVER_SERVER_H
