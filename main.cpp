#include	<cstdlib>
#include	<iostream>
#include	"SafeQueue.hpp"
#include	"Thread.hpp"

Mutex	cout_mutex;

class	Prod : public Thread
{
public:
  static const	int	NB_PRODUCT	= 10;
  static const	int	PRODUCTS	= 100;

private:
  static int		ct;
  int			id_prod;
  int			res;

public:
  Prod() : Thread() { this->id_prod = ++ct; res = 0; }
  ~Prod() {}

  void		*run()
  {
    int		tmp = 0;
    SafeQueue<int>	*queue = reinterpret_cast<SafeQueue<int> *>(this->arg);

    for (int i = 0; !queue->isFinished() && i < Prod::NB_PRODUCT; ++i)
    {
      tmp = (rand() % (PRODUCTS + 1));
      cout_mutex.lock();
      std::cout << "Producer #" << this->id_prod
        	  << " push product " << tmp
        	  << std::endl;
      cout_mutex.unlock();
      queue->push(tmp);
      res += tmp;
    }
    cout_mutex.lock();
    std::cout << "Producer #" << this->id_prod
	      << " has push in total " << res
	      << std::endl;
    cout_mutex.unlock();
    queue->setFinished();

    return (0);
  }
};

class	Cons : public Thread
{
public:
  static const	int	NB_CONSUM = 10;

private:
  int			id_cons;
  int			res;
  static int		ct;

public:
  Cons() : Thread() { this->id_cons = ++ct; res = 0; }
  ~Cons() {}

  void		*run()
  {
    int		tmp = 0;
    SafeQueue<int>	*queue = reinterpret_cast<SafeQueue<int> *>(this->arg);

    while (!queue->isFinished())
      {
        tmp = 0;
        if (queue->tryPop(&tmp)) {
          cout_mutex.lock();
          std::cout << "Consumer #" << this->id_cons
        	  << " pop product " << tmp
        	  << std::endl;
          cout_mutex.unlock();
        } else {
          cout_mutex.lock();
          std::cout << "Consumer #" << this->id_cons
                    << " is waiting" << std::endl;
          cout_mutex.unlock();
          sleep(1); continue;
        }
        res += tmp;
      }
    cout_mutex.lock();
    std::cout << "Consumer #" << this->id_cons
	      << " has pop in total " << res
	      << std::endl;
    cout_mutex.unlock();

    return (0);
  }
};
int	Cons::ct = 0;
int	Prod::ct = 0;


int		main()
{
  srand(time(0));

  SafeQueue<int>	queue;
  Prod		*prod = new Prod;
  Cons		*cons = new Cons;

  prod->start(&queue);
  cons->start(&queue);

  prod->join();
  cons->join();

  delete prod;
  delete cons;

  return (0);
}
