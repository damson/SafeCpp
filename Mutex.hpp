#ifndef	MUTEX_HPP_
# define	MUTEX_HPP_

#include <pthread.h>
#include "IMutex.hpp"

class Mutex : public IMutex
{
public:
  Mutex() {
    pthread_mutex_init(&this->mutex, 0);
  }
  virtual ~Mutex() {
    pthread_mutex_destroy(&this->mutex);
  }
  virtual void	lock() {
    pthread_mutex_lock(&this->mutex);
  }
  virtual void	unlock() {
    pthread_mutex_unlock(&this->mutex);
  }
  virtual bool	trylock() {
    return (pthread_mutex_trylock(&this->mutex));
  }

private:
  pthread_mutex_t	mutex;
};

#endif
