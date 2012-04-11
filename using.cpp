#include <iostream>
#include "ScopedLock.hpp"
#include "Thread.hpp"

#ifndef	N
# define	N	200000
#endif

#ifndef	M
# define	M	2
#endif

struct Param
{
  int		ct;
  Mutex		mutex;
};

class ThreadUsing : public Thread
{
public:
  ThreadUsing() : Thread() {}
  ~ThreadUsing() {}

  void	*run()
  {
    Param *p = reinterpret_cast<Param *>(this->arg);
    ScopedLock lock(&p->mutex);
    for (int i = 0; i < N; ++i)
      ++(p->ct);
  
    return (0);
  }
};

int	main()
{
  ThreadUsing		tab[M];
  Param			p;

  p.ct = 0;
  for (int i = 0; i < M; ++i) {
    tab[i].start(&p);
  }

  for (int i = 0; i < M; ++i) {
    tab[i].join();
  }

  std::cout << "Counter: " << p.ct << std::endl;

  return 0;
}
