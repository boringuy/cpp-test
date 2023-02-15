1) std::getline() does clear the string passed in as reference
2) std::getline() return a reference to the stream, if storing with `auto`, need to use `auto &` 
