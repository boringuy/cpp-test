Various tests for std::vector:
1) iterator doesn't wrap around
2) but if iterator = end() --itr and then ++itr does get back to begin() 
3) when erasing an item from a vector, move constructor will be used to move items up. Same for vector resizing, move constructor is used.
4) vector has constructor to initialize the vector with the same value std::vector a(<size>, <default_value);
5) for 2d vector, can create a 1d vector with default_value to initialized the 2d vector
