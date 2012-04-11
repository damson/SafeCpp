#ifndef	SAFEQUEUE_HPP_
# define	SAFEQUEUE_HPP_

#include	<queue>
#include	"ISafeQueue.hpp"
#include	"Mutex.hpp"

class	SafeQueue : public ISafeQueue
{
public:
  SafeQueue() : _finished(false) {}
  virtual ~SafeQueue(void) {}
  virtual void push(int value);
  virtual bool tryPop(int* value);
  virtual bool isFinished(void);
  virtual void setFinished(void);

private:
  std::queue<int>	_queue;
  bool			_finished;
  Mutex			_mutex;
};

#endif
