Various tests for std::move:
1) instead of using pass by reference, one can pass by value and move the move in when the function is called and move the obj out as return value
2) objects need to be move when returning them in a tuple
