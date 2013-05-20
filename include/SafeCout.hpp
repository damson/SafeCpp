#ifndef	SAFE_COUT_HPP_
# define	SAFE_COUT_HPP_

#include	<iostream>

#include	"Mutex.hpp"

namespace Tools
{
  class SafeCout
  {
  public:
    SafeCout() { cout_mutex.lock(); }
    ~SafeCout() {  cout_mutex.unlock(); }

  private:
    static Mutex	cout_mutex;
  };

  template <typename Type>
  SafeCout const&	operator<<(SafeCout const& sc, Type const& obj) {
    std::cout << obj;

    return (sc);
  }

  SafeCout const&	operator<<
  (SafeCout const& sc, std::ios_base& (*manip)( std::ios_base& ));

  SafeCout const&	operator<<
  (SafeCout const& sc, std::ostream& (*manip)( std::ostream& ));
};

#endif