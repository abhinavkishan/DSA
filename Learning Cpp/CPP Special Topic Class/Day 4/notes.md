# Move Constructor:
```c++
class::function() {
    ex_class ex_obj;
    ...
    return ex_obj; -> extra overhead of copying ex_obj to the caller, we can avoid this by using move constructor 
}
```
- rvalue reference: `&&` -> means that the object is a temporary object

> No virtual constructors as parent constructor is called first. ( Parent Constructor > Child Constructor > Child Destructor > Parent Desctructor)