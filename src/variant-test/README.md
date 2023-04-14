Various tests for std::variant:
1) When a variant is not set to anything, std::holds_alternative() would return true for the first type in the variant list.  
