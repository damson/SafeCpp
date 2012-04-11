#include	<iostream>
#include	"SafeQueue.hpp"
#include	"Thread.hpp"

class	Prod : public Thread
{
public:
  static const	int	NB_PRODUCT = 10;
  static const	int	PRODUCTS = 10;

public:
  Prod() : Thread() {}
  ~Prod() {}

  void		*run()
  {
    SafeQueue	*queue = reinterpret_cast<SafeQueue *>(this->arg);

    for (int i = 0; !queue->isFinished() && i < Prod::NB_PRODUCT; ++i)
      queue->push(PRODUCTS);

    return (0);
  }
};

  int		ct = 0;

class	Cons : public Thread
{
public:
  static const	int	NB_CONSUM = 10;

private:

  int			id_cons;
  int			res;

public:
  Cons() : Thread() { this->id_cons = ++ct; res = 0; }
  ~Cons() {}

  void		*run()
  {
    int		tmp;
    SafeQueue	*queue = reinterpret_cast<SafeQueue *>(this->arg);

    while (queue->tryPop(&tmp))
      {
	std::cout << "Consumer #" << this->id_cons
		  << " pop product " << tmp
		  << std::endl;
	res += tmp;
      }
    std::cout << "Consumer #" << this->id_cons
	      << " has pop in total " << res
	      << std::endl;

    return (0);
  }
};


int		main()
{
  SafeQueue	queue;
  Prod		prod;
  Cons		cons;
  

  prod.start(&queue);
  cons.start(&queue);

  prod.join();
  cons.join();

  return (0);
}
