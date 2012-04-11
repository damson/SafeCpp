#ifndef	ICONDVAR_HPP__
# define	ICONDVAR_HPP__

class ICondVar
{
public:
  virtual ~ICondVar() {}

  virtual void	wait() = 0;
  virtual void	signal() = 0;
  virtual void	broadcast() = 0;
};

#endif	/* !ICONDVAR_HPP__ */