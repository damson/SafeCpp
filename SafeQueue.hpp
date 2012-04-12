#ifndef	SAFEQUEUE_HPP_
# define	SAFEQUEUE_HPP_

# include	<queue>

# include	"ISafeQueue.hpp"
# include	"Mutex.hpp"

template <typename Type>
class	SafeQueue : public ISafeQueue
{
public:
  SafeQueue();
  virtual ~SafeQueue(void) {}
  virtual void push(Type value);
  virtual bool tryPop(Type* value);
  virtual bool isFinished(void);
  virtual void setFinished(void);

private:
  bool			_finished;
  std::queue<Type>	_queue;
  Mutex			_mutex;
};

#endif
