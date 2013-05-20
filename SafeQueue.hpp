#ifndef	SAFEQUEUE_HPP_
# define	SAFEQUEUE_HPP_

# include	<queue>

# include	"ISafeQueue.hpp"
# include	"Mutex.hpp"

template <typename Type>
class	SafeQueue
{
public:
  SafeQueue();
  virtual ~SafeQueue(void) {}
  virtual void		push(Type *value);
  virtual bool		tryPop(Type* value);
  virtual bool		isFinished(void);
  virtual void		setFinished(void);
  virtual bool		isEmpty(void);
  unsigned int	size(void) const;

private:
  bool			_finished;
  std::queue<Type *>	_queue;
  Mutex			_mutex;

private:
  SafeQueue(SafeQueue<Type *> const&) {}
  SafeQueue<Type *>	&operator=(SafeQueue<Type *> const&) { return (*this); }
};

#endif
