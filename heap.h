#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
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
  Heap(int m=2, PComparator c = PComparator());

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
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

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
  std::vector<T> contents_;
  int m_;
  PComparator compare_;

  void heapifyUp(int loc);
  void heapifyDown(int loc);

};

// Add implementation of member functions here
template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_(m), compare_(c){}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  contents_.push_back(item);
  heapifyUp(contents_.size() -1);
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return contents_.empty();
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return contents_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return contents_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }

  std::swap(contents_.front(), contents_.back());
  contents_.pop_back();

  if(!empty()){
    heapifyDown(0);
  }
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int loc){
  while(loc > 0){
    int parent = (loc-1) / m_;
    if(compare_(contents_[loc], contents_[parent])){
      std::swap(contents_[loc], contents_[parent]);
      loc = parent;
    } else {
      break;
    }
  }
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int loc){
  int n = static_cast<int>(contents_.size());
  while(true){
    int priority = loc;
    int first = (m_ * loc) + 1;
    int last = first + (m_ - 1);
    for(int child = first; child <= last && child < n; ++child){
      if(compare_(contents_[child], contents_[priority])){
        priority = child;
      }
    } 
    if(priority == loc){
      break;
    }
    std::swap(contents_[loc], contents_[priority]);
    loc = priority;
  }
}

#endif

