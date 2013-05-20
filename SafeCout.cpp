#include	"SafeCout.hpp"

namespace Tools
{
  Mutex		SafeCout::cout_mutex;

  SafeCout const&	operator<<
  (SafeCout const& sc, std::ios_base& (*manip)( std::ios_base& ))
  {
    std::cout << manip;

    return (sc);
  }

  SafeCout const&	operator<<
  (SafeCout const& sc, std::ostream& (*manip)( std::ostream& ))
  {
    std::cout << manip;

    return (sc);
  }
};
