#include	"CondVar.hpp"

CondVar::CondVar() : Mutex(), _attr(0)
{
  if (pthread_cond_init(&this->_cond, this->_attr))
    std::cerr << "Error: cond init" << std::endl;
}

CondVar::CondVar(pthread_condattr_t *attr) : Mutex(), _attr(attr) {
  if (pthread_cond_init(&this->_cond, this->_attr))
    std::cerr << "Error: cond init" << std::endl;
  if (pthread_condattr_init(this->_attr))
    std::cerr << "Error: cond_attr init" << std::endl;
}

CondVar::~CondVar()
{
  if (pthread_condattr_destroy(this->_attr))
    std::cerr << "Error: cond_attr destroy" << std::endl;
  if (pthread_cond_destroy(&this->_cond))
    std::cerr << "Error: cond destroy" << std::endl;
}

void		CondVar::wait()
{
  if (pthread_cond_wait(&this->_cond, &this->_mutex))
    std::cerr << "Error: cond wait" << std::endl;
}

void		CondVar::signal()
{
  if (pthread_cond_signal(&this->_cond))
    std::cerr << "Error: cond signal" << std::endl;
}

void		CondVar::broadcast()
{
  if (pthread_cond_broadcast(&this->_cond))
    std::cerr << "Error: cond broadcast" << std::endl;
}
