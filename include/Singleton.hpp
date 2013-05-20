#ifndef	SINGLETON_HPP_
# define	SINGLETON_HPP_

# include	"ScopedLock.hpp"
# include	"Tools.hpp"

template <typename T>
class Singleton
{
public:
  static T		*getInstance(void) {
    if (_instance)
      return (_instance);
    if (!_instance) // double-checked locking
      _instance = Tools::checkPointer(new T);
    return (_instance);
  }

  static T const&	getConstInstance(void) {
    return (*getInstance());
  }

protected:
  Singleton() {}
  ~Singleton() {}

private:
  static T		*_instance;
  static Mutex		_mutex;

private:
  Singleton(Singleton<T> const&);
  Singleton<T>	&operator=(Singleton<T> const&);
};

template <typename T>
T			*Singleton<T>::_instance = 0;

#endif
