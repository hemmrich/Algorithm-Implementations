Reverse a string in C++ - std::reverse(str.begin(), str.end());

Association uses a, Aggregation has a, Composition owns a, Inheritance is a
Composition: A consists of B; B is a part of A and hence cannot exist without A
Aggregation: A owns B, B belongs to A
Association: A uses B, A is related to B in a given way

const after a function declaration means that the function is not allowed to change any class members (except ones that are marked mutable). 
So this use of const only makes sense, and is hence only allowed, for member functions.

#define directive is a preprocessor directive; the preprocessor replaces those macros by their body before the compiler even sees it.

private - class only, protected - class and any children of that class

Pass a pointer by reference if you want to change pointer rather than object that pointer is pointing to

Virtual functions allow for dynamic binding by determining correct function call at runtime through vtable

Threads access the same memory space/resources -> need synchronized and lock (Java)
--synchronized prevents threads from executing code simultaneously on same object
--lock - only thread with lock can access resources (only one thread can lock at a time)

Conditions for a deadlock
-Mutual exlusion 
-Hold and wait
-No preemption
-Circular wait

Min STL priority queue - priority_queue<int, vector<int>, std::greater<int> > my_min_heap;

Find k largest values in array? Use a min-heap (k smallest? use max heap)

Inheritance diamond - fix by making middle level class Tiger : virtual public Animal

need virtual destructor to ensure that subclass destructors are called when using polymorphism



Fastest way to find largest element in circular sorted array?

BST + int n, find most efficient way to find two nodes that sum to n?

How to convert a max heap to a min heap?

Space/time complexity of recursive functions?

How to implement three stacks with one array?

Find power set of a given set in C++?

Find out if binary tree is mirror of itself?

Implement own hashtable?

Implement itoa?

Initialize function pointer?

Reverse a linked list recursively?



