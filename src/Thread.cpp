#include	<iostream>
#include  "Thread.hpp"
#include  "Tools.hpp"

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
    throw Tools::Exception("Error: pthread attributes destroy");
  pthread_exit(&this->_id);
}

void			Thread::start(void *arg)
{
  this->arg = arg;

  if (this->_attr && pthread_attr_init(this->_attr))
    throw Tools::Exception("Error: pthread attributes init");
  if (pthread_create(&this->_id, this->_attr, &Thread::exec, this))
    throw Tools::Exception("Error: thread creation");
  this->_state = RUNNABLE;
}

void			Thread::join(void)
{
  if (pthread_join(this->_id, 0))
    throw Tools::Exception("Error: thread join");
  this->_state = TERMINATED;
}

bool			Thread::suspend(void)
{
  if (this->_state == WAITING)
    return (false);
  this->_state = WAITING;
  this->_cvar.wait();
  return (true);
}

bool			Thread::sleep(long sec)
{
  if (this->_state == TIMED_WAITING)
    return (false);
  this->_state = TIMED_WAITING;
  this->_cvar.wait(sec);
  this->_state = RUNNABLE;
  return (true);
}

bool			Thread::usleep(long sec)
{
  if (this->_state == TIMED_WAITING)
    return (false);
  this->_state = TIMED_WAITING;
  this->_cvar.nanowait(sec * 1000000);
  this->_state = RUNNABLE;
  return (true);
}

bool			Thread::resum(void)
{
  return (this->resum(this->arg));
}

bool			Thread::resum(void *arg)
{
  if (this->_state != WAITING && this->_state != TIMED_WAITING)
    return (false);
  this->_cvar.signal();
  this->arg = arg;
  this->_state = RUNNABLE;
  return (true);
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
  return ((static_cast<Thread *>(thread))->run());
}
