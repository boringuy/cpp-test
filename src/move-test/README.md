Various tests for std::move:
1) instead of using pass by reference, one can pass by value and move the value in when the function is called and move the obj out as return value
2) objects need to be moved when returning them in a tuple
3) when using emplace_back, the key is to use the initialization parameter directly and not to create the object. 
4) std::make_unique() can be used to create a unique pointer that will get moved into a function or object constructor without explicitly moving
5) https://stackoverflow.com/questions/8114276/how-do-i-pass-a-unique-ptr-argument-to-a-constructor-or-a-function#:~:text=Recommendations,this%20whenever%20possible.
   Recommendations:
     (A) By Value: If you mean for a function to claim ownership of a unique_ptr, take it by value.
     (C) By const l-value reference: If you mean for a function to simply use the unique_ptr for the duration of that function's execution, take it by const&. Alternatively, pass a & or const& to the actual type pointed to, rather than using a unique_ptr.
     (D) By r-value reference: If a function may or may not claim ownership (depending on internal code paths), then take it by &&. But I strongly advise against doing this whenever possible.
6) If an argument is universal reference "&&", you have to move when calling the function or it would fail to compile
7) When passing shared_ptr into an object to be store, we can move it into the member because it's already made a copy when calling into the object, no point to make yet another copy incrementing the count and decrement it again.

