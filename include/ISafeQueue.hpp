#ifndef	ISAFEQUEUE_HPP_
# define	ISAFEQUEUE_HPP_

class	ISafeQueue
{
public:
  virtual ~ISafeQueue(void) {}
  virtual void push(int value) = 0;
  virtual bool tryPop(int* value) = 0;
  virtual bool isFinished(void) = 0;
  virtual void setFinished(void) = 0;
};

#endif
