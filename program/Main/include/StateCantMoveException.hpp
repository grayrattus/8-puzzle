#include <exception>
using namespace std;

class StateCantMoveException: public exception
{
  virtual const char* what() const throw()
  {
    return "Can't move.";
  }
};