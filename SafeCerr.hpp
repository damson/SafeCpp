#ifndef	SAFE_CERR_HPP_
# define	SAFE_CERR_HPP_

#include	<iostream>

#include	"Mutex.hpp"

namespace Tools
{
  class SafeCerr
  {
  public:
    SafeCerr() { cerr_mutex.lock(); }
    ~SafeCerr() {  cerr_mutex.unlock(); }

  private:
    static Mutex	cerr_mutex;
  };

  template <typename Type>
  SafeCerr const&	operator<<(SafeCerr const& sc, Type const& obj) {
    std::cerr << obj;
  
    return (sc);
  }

  SafeCerr const&	operator<<
  (SafeCerr const& sc, std::ios_base& (*manip)( std::ios_base& ));

  SafeCerr const&	operator<<
  (SafeCerr const& sc, std::ostream& (*manip)( std::ostream& ));
};

#endif