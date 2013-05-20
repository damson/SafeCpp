#ifndef TOOLS_HPP_
# define	TOOLS_HPP_

# include	<sstream>

# include	"Exception.hpp"

namespace Tools
{
  template <typename T>
  T	stringTo(std::string const &str)
  {
    std::stringstream	ss(str);
    T	value;

    ss >> value;
    return (value);
  }

  template <typename T>
  T	stringTo(const char *str)
  {
    return (stringTo<T>(std::string(str)));
  }

  template <typename T>
  std::string const	toString(T const& value)
  {
    std::stringstream	ss;

    ss << value;
    return (ss.str());
  }

  template <typename T>
  T	*checkPointer(T *ptr)
  {
    if (!ptr)
      throw Exception("Pointer NULL.");
    return (ptr);
  }
}

#endif
