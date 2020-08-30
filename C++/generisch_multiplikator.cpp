
#include <iostream>
#include <stack>
#include <queue>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/adaptors.hpp>
#include <algorithm>
#include <boost/range.hpp>


template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type
product(Iterator begin, Iterator end){
   using Type = typename std::iterator_traits<Iterator>::value_type;

   return boost::accumulate(boost::make_iterator_range(begin, end), Type(1), 
   [](const Type& a, const Type& b){return a * b;});
