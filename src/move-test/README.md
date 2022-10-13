Various tests for std::move:
1) instead of using pass by reference, one can pass by value and move the value in when the function is called and move the obj out as return value
2) objects need to be moved when returning them in a tuple
3) when using emplace_back, the key is to use the initialization parameter directly and not to create the object. 
4) std::make_unique() can be used to create a unique pointer that will get moved into a function or object constructor without explicitly moving
