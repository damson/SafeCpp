#include	<iostream>
#include	"thread.hpp"

Thread::~Thread()
{
  pthread_attr_destroy(this->_attr);
  pthread_exit(this->_id);
}

void		Thread::start(void *arg)
{
  this->_arg = arg;
  if (pthread_create(&this->id, &this->_attr, &Thread::exec, this))
    std::cerr << "Error: thread creation" << std::endl;
}

void		Thread::join(void)
{
  pthread_join(this->_id);
}

void		*Thread::exec(void *thread)
{
  return ((reinterpret_cast<Thread *>(thread))->run());
}
