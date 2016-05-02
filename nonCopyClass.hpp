/**
 *  Copyright 2016 <Hung Q. Nguyen>
 *  @file    nonCopyClass.hpp
 *  @author  Hung Q. Nguyen
 *  @date    2/24/2016
 *  @version Doxygen 1.8.11
 *  
 *  @brief The implementations of a Non Copyable objetc
 */

class NonCopyClass {
 public:
 protected:
  NonCopyClass() {}
  ~NonCopyClass() {}
 private:
  NonCopyClass(const NonCopyClass&);
  NonCopyClass& operator = (const NonCopyClass &);
};
