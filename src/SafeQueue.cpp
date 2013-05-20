#include	"ScopedLock.hpp"
#include	"SafeQueue.hpp"
#include	"ThreadPool.hpp"

template <typename Type>
SafeQueue<Type>::SafeQueue() : _finished(false)
{
  ;
}

template <typename Type>
void		SafeQueue<Type>::push(Type *value)
{
  ScopedLock	lock(&this->_mutex);

  if (!this->_finished)
    this->_queue.push(value);
}

template <typename Type>
bool		SafeQueue<Type>::tryPop(Type *value)
{
  ScopedLock	lock(&this->_mutex);

  if (!this->_queue.empty())
    {
      value = new Type(*this->_queue.front());
      this->_queue.pop();
      return (true);
    }
  return (false);
}

template <typename Type>
unsigned int	SafeQueue<Type>::size(void) const
{
  return (this->_queue.size());
}

template <typename Type>
bool	SafeQueue<Type>::isEmpty(void)
{
  return (this->_queue.empty());
}

template <typename Type>
bool		SafeQueue<Type>::isFinished()
{
  if (this->_finished && this->_queue.empty())
    return (true);
  return (false);
}

template <typename Type>
void		SafeQueue<Type>::setFinished()
{
  this->_finished = true;
}




template SafeQueue<int>::SafeQueue();
template void    SafeQueue<int>::push(int *value);
template bool    SafeQueue<int>::tryPop(int *value);
template bool    SafeQueue<int>::isFinished();
template void    SafeQueue<int>::setFinished();
template bool    SafeQueue<int>::isEmpty();
template unsigned int    SafeQueue<int>::size() const;

// template SafeQueue<Task>::SafeQueue();
// template void    SafeQueue<Task>::push(Task * value);
// template bool    SafeQueue<Task>::tryPop(Task *value);
// template bool    SafeQueue<Task>::isFinished();
// template void    SafeQueue<Task>::setFinished();
// template bool    SafeQueue<Task>::isEmpty();
// template unsigned int    SafeQueue<Task>::size() const;
