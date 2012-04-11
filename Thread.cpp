#include	<iostream>
#include	"Thread.hpp"

Thread::Thread() : _attr(0), _state(NEW)
{
  ;
}

Thread::Thread(pthread_attr_t* attr) : _attr(attr), _state(NEW)
{
  ;
}

Thread::~Thread()
{
  if (this->_attr && pthread_attr_destroy(this->_attr))
    std::cerr << "Error: pthread attributes destroy" << std::endl;
  pthread_exit(&this->_id);
}

void			Thread::start(void *arg)
{
  this->arg = arg;

  if (this->_attr && pthread_attr_init(this->_attr))
    std::cerr << "Error: pthread attributes init" << std::endl;
  if (pthread_create(&this->_id, this->_attr, &Thread::exec, this))
    std::cerr << "Error: thread creation" << std::endl;
  this->_state = RUNNABLE;
}

void			Thread::join(void)
{
  if (pthread_join(this->_id, 0))
    std::cerr << "Error: thread join" << std::endl;
  this->_state = TERMINATED;
}

pthread_t const&	Thread::getId(void) const
{
  return (this->_id);
}

Thread::e_TState	Thread::getState(void) const
{
  return (this->_state);
}

void			*Thread::exec(void *thread)
{
  return ((reinterpret_cast<Thread *>(thread))->run());
}
