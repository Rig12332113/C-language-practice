#include "locker.h"

void init(Lock *lock){
    lock->situation = 0;
}
int lock(Lock *lock, int combination){
    if (lock->situation == 1)
        return -1;
    else{
        if (combination < 0 || combination > 9999)
            return 10000;
        else{
            lock->password = combination;
            lock->situation = 1;
            return combination;
        }
    }
}
int unlock(Lock *lock, int combination){
    if (lock->situation == 0)
        return -1;
    else{
        if (lock->password == combination){
            lock->situation = 0;
            return 0;
        }
        else
            return 1;
    }
    
}
int isLocked(Lock *lock){
    return lock->situation;
}