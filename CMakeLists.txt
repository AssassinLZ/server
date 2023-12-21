cmake_minimum_required(VERSION 3.24)
project(server)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        server src/main.cc
        src/EventLoop.cc
        src/EventLoop.h
        src/Channel.cc
        src/Channel.h
        src/Epoll.cc
        src/Epoll.h
        src/EventLoopThread.cc
        src/EventLoopThread.h
        src/HttpData.cc
        src/HttpData.h
        src/Server.cc
        src/Server.h
        src/ThreadPool.cc
        src/ThreadPool.h
        src/Timer.cc
        src/Timer.h
        src/Util.cc
        src/Util.h
        src/EventLoopThreadPool.cc
        src/EventLoopThreadPool.h
)