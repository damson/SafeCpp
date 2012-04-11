#ifndef THREAD_HPP_
# define	THREAD_HPP_

class Thread
{
public:
  // maybe one specific constructor to set attributes 
  Thread() {}
  virtual ~Thread();

  void			start(void *arg);
  void			join(void);
  virtual void		*run(void) = 0;

protected:
  void			*arg;
  static void		*exec(void *);

private:
  pthread_t		_id;		// thread id
  pthread_attr_t	_attr;		// thread attributes

// NonCopyable
private:
  Thread(Thread const&) {}
  Thread		&operator=(Thread const&) { return (*this); }
};

#endif