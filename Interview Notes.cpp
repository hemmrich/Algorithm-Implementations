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


Problems:
1) Given unsorted array, determine how many pairs of numbers add to X
   Approach 1: Sort array (nlogn), ptr to beginning and end, if sum is too small, advance beginning ptr, if too large, move end backwards
   Approach 2: Put all elements in to hashtable (n), travserse through and see if x - HT[i] is in hashtable (n)


2) Lowest common ancestor of binary tree
   Approach: Inorder traversal, postorder traversal
             create list of all elements between X and Y in inorder traversal
             the element in the list above that is closest to end of postorder is the LCA




MATHWORKS

#define X 10 -> preprocessor directive, gets replaced before compilation

Mealy State Machine- output based on both state and input
Moore State Machine- output based only on state

bits needed for ROM = 2^(state bits + inputs) entries of (state bits + outputs)

Finite automata
Sigma - alphabet
Q - set of states
delta - set of transitions between stats
q0 - initial state
F - set of accept states

Pidgenhole principle - if N objects are placed into k boxes, then there is at least 
one box containing at least ceil(N/k) objects









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



