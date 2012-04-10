#ifndef	IMUTEXT_HPP_
# define	IMUTEXT_HPP_

class IMutex
{
public:
  virtual ~IMutex() {};
  virtual void	lock() = 0;
  virtual void	unlock() = 0;
  virtual bool	trylock() = 0;
};

#endif
