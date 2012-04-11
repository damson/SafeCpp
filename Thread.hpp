#ifndef THREAD_HPP_
# define	THREAD_HPP_

class Thread
{
public:
	enum e_TState
	  {
            NEW,
            RUNNABLE,
            TERMINATED
	  };

public:
  // maybe one specific constructor to set attributes 
  Thread() : _state(NEW) {  }
  virtual ~Thread();

  void			start(void *arg);
  void			join(void);
  e_TState		getState(void) const;
  virtual void		*run(void) = 0;

protected:
  void			*arg;
  static void		*exec(void *);

private:
  pthread_t		_id;		// thread id
  pthread_attr_t	_attr;		// thread attributes
  e_TState		_state;

// NonCopyable
private:
  Thread(Thread const&) {}
  Thread		&operator=(Thread const&) { return (*this); }
};

#endif