#ifndef	CONDVAR_HPP__
# define	CONDVAR_HPP__

#include	<iostream>

#include	"Mutex.hpp"
#include	"ICondVar.hpp"

class CondVar : public Mutex, public ICondVar
{
public:
  CondVar();
  CondVar(pthread_condattr_t *attr);
  virtual ~CondVar();

  virtual void		wait();
  virtual void		signal();
  virtual void		broadcast();

private:
  pthread_cond_t	_cond;
  pthread_condattr_t	*_attr;
};

#endif	/* !CONDVAR_HPP__ */
