#include	"SafeQueue.hpp"

void		SafeQueue::push(int value)
{
  this->_queue.push(value);
}

bool		SafeQueue::tryPop(int *value)
{
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
  if (this->_finished && this->queue.empty())
    return true;
  return false;
}

void		SafeQueue::setFinished()
{
  this->_finished = true;
}
