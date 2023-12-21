//
// Created by Assassin on 12/21/23.
//

#include "EventLoop.h"

void EventLoop::wakeup() {
    uint64_t one = 1;
    ssize_t n = writen(wakeupFd_, (char*)(&one), sizeof one);
    if(n != sizeof one){
        LOG << "EventLoop::wakeup() writes " << n << " bytes instead of 8";
    }
}
