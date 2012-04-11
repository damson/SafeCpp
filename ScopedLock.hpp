#ifndef SCOPED_LOCK_HPP
# define	SCOPED_LOCK_HPP

#include	"Mutex.hpp"

class ScopedLock
{
public:
  ScopedLock(Mutex *mutex) : _mutex(mutex) {
    this->_mutex->lock();
  }
  ~ScopedLock() {
    this->_mutex->unlock();
  }

private:
  Mutex	*_mutex;

private:
  ScopedLock() {}
  ScopedLock(ScopedLock const&) {}
  ScopedLock &	operator=(ScopedLock const&) { return (*this);}
};

#endif
