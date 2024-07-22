Various tests for STL algorithm:
1) when using std::lower_bound() and std::upper_bound() for search, if the element doesn't exists, both will return the next element that's greater than the search value. It can be the end() itr if it reaches the end
2) if exists, lower_bound() will return the itr for the search value, upper_bound will return the next element
3) erasing will cause the iterator to change or become invalid.
   
