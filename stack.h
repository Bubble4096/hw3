#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};


/////////////////////////////////NOT COMPLETE//////////////////////////
template <typename T>
Stack<T>::~Stack()
{

}
template <typename T>
Stack<T>::Stack()
{

}


template <typename T>
void Stack<T>::push(const T& item)
{ 
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
  // size validation
  if(empty() == true){
    throw std::underflow_error("stack is empy");
  } else {
   std::vector<T>::pop_back();
  }
}

template <typename T>
const T& Stack<T>::top() const
{
  // return top item
  if(empty() == true){
    throw std::underflow_error("stack is empy");
  } else 
  {
    return std::vector<T>::at(size()-1);
  }
}


/////////////////////////////////COMPLETED//////////////////////////
template <typename T>
bool Stack<T>::empty() const
{
  if(std::vector<T>::size() == 0) {
    return true;
  } 
  else {
    return false;
  }

}

// COMPLETE
template <typename T>
size_t Stack<T>::size() const
{
  size_t ret_val = std::vector<T>::size();
  return ret_val;
}
#endif