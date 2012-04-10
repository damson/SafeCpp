#include <iostream>
#include "ScopedLock.hpp"

#ifndef	N
# define	N 200000
#endif

#ifndef	M
# define	M	2
#endif

struct Param
{
  Mutex	mutex;
  int		ct;
};

void	*increment_counter(void *p)
{
  ScopedLock	sl(&(((Param *)p)->mutex));

  for (int i = 0; i < N; ++i)
    ++(((Param *)p)->ct);

  return (0);
}

int main()
{
  pthread_t		tab[M];
  Param			p;

  p.ct = 0;
  for (int i = 0; i < M; ++i) {
    if (pthread_create(&(tab[i]), 0, &increment_counter, &p)) {
      std::cerr << "Error: thread creation" << std::endl;
      throw std::exception();
    }
  }

  for (int i = 0; i < M; ++i) {
    pthread_join(tab[i], 0);
  }

  std::cout << "Counter: " << p.ct << std::endl;

  for (int i = 0; i < M; ++i)
    pthread_exit(&(tab[i]));

  return 0;
}
