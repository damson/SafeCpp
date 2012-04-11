#ifndef	MUTEX_HPP_
# define	MUTEX_HPP_

#include <pthread.h>
#include "IMutex.hpp"

class Mutex : public IMutex
{
public:
  Mutex() {
    pthread_mutex_init(&this->_mutex, 0);
  }
  virtual ~Mutex() {
    pthread_mutex_destroy(&this->_mutex);
  }
  virtual void	lock() {
    pthread_mutex_lock(&this->_mutex);
  }
  virtual void	unlock() {
    pthread_mutex_unlock(&this->_mutex);
  }
  virtual bool	trylock() {
    return (pthread_mutex_trylock(&this->_mutex));
  }

protected:
  pthread_mutex_t	_mutex;

// NonCopyable
protected:
  Mutex(Mutex const&) {}
  Mutex &operator=(Mutex const&) { return (*this); }
};

#endif
