#include	"ScopedLock.hpp"
#include	"SafeQueue.hpp"

SafeQueue::SafeQueue() : _finished(false)
{
  ;
}

void		SafeQueue::push(int value)
{
  ScopedLock	lock(&this->_mutex);

  if (!this->_finished)
    this->_queue.push(value);
}

bool		SafeQueue::tryPop(int *value)
{
  ScopedLock	lock(&this->_mutex);

  if (!this->_queue.empty())
    {
      *value = this->_queue.front();
      this->_queue.pop();
      return true;
    }
  return false;
}

bool		SafeQueue::isFinished()
{
  if (this->_finished && this->_queue.empty())
    return true;
  return false;
}

void		SafeQueue::setFinished()
{
  this->_finished = true;
}
