#ifndef THREAD_HPP_
# define	THREAD_HPP_

# include	<pthread.h>

# include	"CondVar.hpp"

class Thread
{
public:
  enum e_TState
    {
      NEW,
      RUNNABLE,
      WAITING,
      TIMED_WAITING,
      TERMINATED
    };

public:
  // maybe one specific constructor to set attributes 
  Thread();
  Thread(pthread_attr_t *);
  virtual ~Thread();

  void			start(void *arg = 0);
  void			join(void);
  bool			sleep(long);
  bool			usleep(long);
  bool			suspend(void);
  bool			resum(void *);
  bool			resum(void);
  pthread_t const&	getId(void) const;
  e_TState		getState(void) const;
  virtual void		*run(void) = 0;

protected:
  void			*arg;
  static void		*exec(void *);

private:
  pthread_t		_id;		// thread id
  pthread_attr_t	*_attr;		// thread attributes
  e_TState		_state;
  CondVar		_cvar;

// NonCopyable
private:
  Thread(Thread const&) {}
  Thread		&operator=(Thread const&) { return (*this); }
};

#endif
