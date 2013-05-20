#include	"SafeCerr.hpp"

namespace Tools
{
  Mutex		SafeCerr::cerr_mutex;

  SafeCerr const&	operator<<
  (SafeCerr const& sc, std::ios_base& (*manip)( std::ios_base& ))
  {
    std::cerr << manip;

    return (sc);
  }

  SafeCerr const&	operator<<
  (SafeCerr const& sc, std::ostream& (*manip)( std::ostream& ))
  {
    std::cerr << manip;

    return (sc);
  }
};
