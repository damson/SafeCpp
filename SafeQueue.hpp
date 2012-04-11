#ifndef	SAFEQUEUE_HPP_
# define	SAFEQUEUE_HPP_

#include	<queue>
#include	"ISafeQueue.hpp"
#include	"Mutex.hpp"

class	SafeQueue : public ISafeQueue
{
public:
  SafeQueue();
  virtual ~SafeQueue(void) {}
  virtual void push(int value);
  virtual bool tryPop(int* value);
  virtual bool isFinished(void);
  virtual void setFinished(void);

private:
  bool			_finished;
  std::queue<int>	_queue;
  Mutex			_mutex;
};

#endif
