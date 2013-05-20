#ifndef	THREADPOOL_HPP__
# define	THREADPOOL_HPP__

# include	<iostream>

# include	"SafeQueue.hpp"

class Task
{
public:
  virtual ~Task() {}
  virtual void		toRun() = 0;
  std::string const&    getName() const { return (this->_name); }
  unsigned int          getId() const { return (this->_id); }

private:
  unsigned int		_id;
  std::string		_name;
};

class ThreadPool
{
public:
  static const int	NB_THREAD_MIN = 2;

public:
  ThreadPool(int = NB_THREAD_MIN);
  ~ThreadPool();

  bool			create();
  void			destroy();
  bool			assignTask(Task *);
  void			executeTasks();
  unsigned int		getPoolSize() const;

private:
  SafeQueue<Task *>	_tasks();
  int			_nbThread;
  int			_remainingTask;

private:
  ThreadPool(ThreadPool const&) {}
  ThreadPool	&operator=(ThreadPool const&) { return (*this); }
};

#endif	/* !THREADPOOL_HPP__ */