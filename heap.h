#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
   * @brief Destroy the Heap object
   *
   */
  ~Heap();

  /**
   * @brief Push an item to the heap
   *
   * @param item item to heap
   */
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

  /**
   * @brief Remove the top priority item
   *
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   *
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   *
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> vect_; // heap storage
  int m; // default val
  PComparator c; // default val 
  // takes in index to give parent
  int parent(int index);

  // ith child of index
  int ithChild(int index, int i) const;

  // trickle up function to heapify
  void trickleUp(int index);

  // trickle down function to heapify
  void trickleDown(int index);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int index)
{
  return (index - 1) / m;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::ithChild(int index, int i) const
{
  return m * index + i;
}
// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empy");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return vect_[0];
  }
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empy");
    return;
  }
  else
  {
    vect_[0] = vect_.back();
    vect_.pop_back();
    trickleDown(0);
  }
}
// checks if empty 
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return vect_.empty();
}

// push to heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &val)
{
  vect_.push_back(val);
  trickleUp(vect_.size() - 1);
}
// trickles values up
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index)
{
  T value = vect_[index];

  while (index > 0 && c(value, vect_[parent(index)]))
  {
    vect_[index] = vect_[parent(index)];
    index = parent(index);
  }

  vect_[index] = value;
}
// trickles values down
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index)
{
  size_t child = ithChild(index, 1);
  T value = vect_[index];

  while (child < vect_.size())
  {
    int minChild = child;
    int k = 2;

    while (k <= m && (child + k - 1) < vect_.size())
    {
      int nextChild = ithChild(index, k);
      if (c(vect_[nextChild], vect_[minChild]))
      {
        minChild = nextChild;
      }
      k++;
    }

    if (c(vect_[minChild], value))
    {
      vect_[index] = vect_[minChild];
      index = minChild;
      child = ithChild(index, 1);
    }
    else
    {
      break;
    }
  }

  vect_[index] = value;
}

#endif
