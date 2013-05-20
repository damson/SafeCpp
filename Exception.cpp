#include	<sstream>
#include	"Exception.hpp"

namespace Tools
{
  Exception::Exception(std::string const& msg)
    : _msg(msg)
  {
    ;
  }

  char const		*Exception::what() const throw()
  {
    return (this->_msg.c_str());
  }

  std::string const&	Exception::where() const throw()
  {
    return (this->_where);
  }

  template <typename Type>
  void			Exception::setWhere(Type const& where) throw()
  {
    std::stringstream   ss;

    ss << where;
    ss >> this->_where;
  }

  template void   Exception::setWhere<unsigned int>(unsigned int const&) throw();
  template void   Exception::setWhere<int>(int const&) throw();
  template void   Exception::setWhere<std::string>(std::string const&) throw();
}
