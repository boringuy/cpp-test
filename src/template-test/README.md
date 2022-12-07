various tests for templates:
1) template type can be deduced automatically when calling template function, no need to specific it
2) template can be used to accept lambda function as parameter without specifying the parameter of the lambda function; however, the return type must be explicitly specified
3) When "regular" template and "lambda" template are used, put the "lambda" template at the end so you can specify the "regular" template when calling the function but still don't need to specify the lambda function parameters
4) auto&& can also be used to added lambda function as parameter but needs "-fconcepts" flag
