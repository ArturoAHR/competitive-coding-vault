#include <bits/stdc++.h>

/*
 * ODI Camp Class - Data Structures
 */

using namespace std;

// Primitive Types
void primitiveTypes() {
  /*
    Primitive types are those who come in-built into the language.
  */

  int myInt = 4; // Stores numbers in the range [-2 ^ 31, 2 ^ 31 = 1].
  unsigned int myUnsignedInt = 5; // Can store in range [0, 2 ^ 32 - 1].
  char myChar = 'x';  // Follows the ASCII codes to represent characters.
  bool myBool = true; // Can be added like an integer, true is 1, false is 0.
  int64_t myLong = LLONG_MAX;   // Can store in  range [-2 ^ 63, 2 ^ 63 - 1].
  uint64_t myUnsignedLong = 10; // Can store in range [0, 2 ^ 64 - 1].
  double myDouble = 123456789.123456789; // Able to hold large decimal values.
  float myFloat = 4.2; // less capacity than double but uses less memory.

  /*
    All of these primitives can be printed without needing an special
    implementation for them
  */
  cout << myInt << ' ' << myUnsignedInt << ' ' << myChar << ' ' << myBool << ' '
       << myDouble << ' ' << myFloat << ' ' << myLong << ' ' << myUnsignedLong
       << '\n';

  /*
    Integer literals are by default of type int, be careful when using them in
    calculations that are meant to be stored in long long variables.

    Adding LL to the number literal will make it a long long.
  */
  cout << 100000000 * 100 << ' ' << 100000000LL * 100 << '\n';
}

// Console I/O
void consoleIO() {
  /*
    Most primitive and some non-primitive variables can be read directly from
    console input.
  */
  int n;
  string s;

  /*
    We can read variable of different types with cin as long as these are
    separated by a space or a newline (When you press enter).
  */
  cin >> n >> s;

  /* We can also output these variables with cout. */
  cout << n << ' ' << s << '\n';

  /*
    The reason we use '\n', instead of std::endl for line endings is that '\n'
    is faster than std::endl as the latter forces a flush of the output buffer.
  */

  /*
    You can use cerr to print debug logs that won't be seen by the judge.
    It does increase the runtime of a program though, so be careful while using
    it so you don't run into Time Limit Errors.
  */
  cerr << n << ' ' << s << '\n';

  /*
    With getline you can get a whole line of characters as a string until a
    newline character ('\n') appears, useful when you need to read a string that
    is supposed to contain spaces.
  */

  /*
    Flushing out any unwanted remaining contents in std::cin's buffer, this is
    necessary if you mix std::cin and std::getline for reading input
  */
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  getline(cin, s);

  cout << s;
}

// Arrays
void arrays() {
  /*
    Arrays can be declared with or without values.
  */
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int b[10];

  /*
    You can set all of the values in an int array to -1 with std::memset.
    This will be useful for the implementation of advanced algorithms.
  */
  memset(b, -1, sizeof(b));

  /*
    And output the values in an array looping through its values.
    These are two examples of how to do it;
  */
  for (int i = 0; i < 10; i++) {
    if (i > 0)
      cout << ' ';
    cout << a[i]; // 1 2 3 4 5 6 7 8 9 10
  }
  cout << '\n';

  for (int v : b) {
    cout << v << ' '; // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
  }
  cout << '\n';

  /*
    Similarly to read inputs we need to iterate through the arrays values to
    assign what's read in each iteration.
  */
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }

  /*
    Note: Here we change the loop definition to be able to modify our array, we
    need to add an ampersand symbol (&) before the name of the first variable so
    the space in memory the array value is in is passed in *By Reference*, any
    changes to that variable will reflect on the array value in the current
    position.
  */
  for (int &v : b) {
    cin >> v;
  }

  /*
    Let's output again the values of our arrays
  */
  for (int i = 0; i < 10; i++) {
    if (i > 0)
      cout << ' ';
    cout << a[i];
  }
  cout << '\n';

  for (int v : b) {
    cout << v << ' ';
  }
  cout << '\n' << '\n';

  /*
    You can create arrays of arrays to have matrices of higher dimensions.
  */
  int c[10][10];

  /*
    To loop through arrays of higher dimensions you need to use nested loops to
    access each dimension up until you can access the dimensions where values
    are stored in. Since this array is a 2D matrix we are using 2 loops.
  */
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      c[i][j] = (i + 1) * (j + 1);
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (j > 0)
        cout << ' ';
      cout << c[i][j];
    }
    cout << '\n';
  }

  /*
    Getting the size of an array is a bit tricky, this is why we only use arrays
    when we know for sure what's the amount of elements we will be storing in
    it.
  */
  cout << sizeof(a) / sizeof(a[0]) << '\n';
}

// Strings
void strings() {
  /*
    Strings could be considered as an array of chars.
  */
  string str = "hello world";

  cout << str << '\n';                              // hello world
  cout << str[0] << ' ' << str[10] << '\n' << '\n'; // h d

  /*
    Strings contain many functionalities that can be useful.
  */

  // Size method to get string size
  cout << str.size() << '\n'; // 11

  // You can append other strings
  cout << str + " and goodbye" << '\n'; // hello world and goodbye

  // You can replace characters.
  cout << str.replace(6, 5, "universe") << '\n'; // hello universe

  // Find where a substring starts, O(n*m) time complexity.
  cout << str.find("universe") << '\n'; // 6

  // Erase characters in a range, O(n) time complexity.
  str.erase(str.begin(), str.begin() + 6);
  cout << str << '\n'; // universe
}

// Vectors
void vectors() {
  /*
    Vectors are arrays that can expanded dynamically.
  */
  vector<int> a;       // Declaration without initialization.
  vector<int> b(5, 0); // Declaration with initialization, this vector has 5
                       // spaces with 0 in each of them

  a.push_back(1); // Inserts elements at the end in O(1), a: 1
  a.push_back(2); // a: 1 2

  cout << a[0] << '\n' << '\n'; // 1

  a.pop_back(); // Removes characters at the end in O(1), a: 1

  a.erase(a.begin()); // Removes the first character in O(n), a is empty now

  a.push_back(3); // a: 3
  a.push_back(2); // a: 3 2
  a.push_back(1); // a: 3 2 1

  cout << a.empty() << '\n';        // Returns true if vector is empty.
  cout << a.size() << '\n' << '\n'; // Gets the size of the vector.

  a.clear(); // a is empty now

  /*
    You can chain vectors to create 2D arrays of elements of any dimension you
    like.
  */
  vector<vector<int>> c;

  /*
    These vectors of vectors are special since each "row" can have different
    lengths.
  */

  c.push_back(vector<int>(3));
  c.push_back(vector<int>(1));

  cout << c[0].size() << ' ' << c[1].size() << '\n';
}

// Stack
void stacks() {
  /*
    Stacks are a data structure in which elements that enter last are the first
    to exit.
  */
  stack<int> s;

  s.push(5);  // s: 5
  s.push(10); // s: 5 10
  s.push(20); // s: 5 10 20

  // Outputs the element on top of the stack: 20.
  cout << s.top() << '\n';
  // Gets the size of the stack.
  cout << s.size() << '\n';
  // Returns true if the stack is empty.
  cout << s.empty() << '\n';
  cout << '\n';

  s.pop(); // s: 5 10. Removing elements from a stack has O(1) time complexity.

  cout << s.top() << '\n'; // 10
  cout << '\n';

  /*
    If we want to loop through the elements of a stack we can do the following.
  */
  while (!s.empty()) {
    int currentValue = s.top();

    cout << currentValue << '\n';

    s.pop();
  }
}

// Queue
void queues() {
  /*
    Queues are a data structure in which elements that enter first are the first
    to exit as well.
  */
  queue<int> q;

  q.push(5);  // q: 5
  q.push(10); // q: 5 10
  q.push(20); // q: 5 10 20

  // Outputs the element in the front of the queue: 5.
  cout << q.front() << '\n';
  // Outputs the last element in the queue: 20.
  cout << q.back() << '\n';
  // Gets the size of the queue.
  cout << q.size() << '\n';
  // Returns true if the queue is empty.
  cout << q.empty() << '\n';
  cout << '\n';

  q.pop(); // q: 10 20. Removing elements from a queue has O(1) time complexity.

  cout << q.front() << '\n'; // 10
  cout << '\n';

  /*
    If we want to loop through the elements of a queue we can do the following.
  */
  while (!q.empty()) {
    int currentValue = q.front();

    cout << currentValue << '\n';

    q.pop();
  }
}

// Deques
void deques() {
  /*
    Deques are a data structure that is a double ended queue, meaning that
    elements in the front and the back can be efficiently inserted or removed as
    needed.
  */
  deque<int> d;

  d.push_back(5);   // d: 5
  d.push_front(10); // d: 10 5
  d.push_back(20);  // d: 10 5 20

  // Outputs the element in the front of the deque: 10.
  cout << d.front() << '\n';
  // Outputs the last element in the deque: 20.
  cout << d.back() << '\n';
  // Gets the size of the deque.
  cout << d.size() << '\n';
  // Returns true if the deque is empty.
  cout << d.empty() << '\n';
  cout << '\n';

  // Removing elements in the front or the back of a deque has a O(1) time
  // complexity
  d.pop_front(); // d: 5 20
  d.pop_back();  // d: 5.

  d.erase(d.begin()); // However, removing elements using erase has a O(n) time
                      // complexity.

  /*
    If we want to loop through the elements of a deque we can do the following.
  */
  d = {9, 5, 1, 3, 7};

  while (!d.empty()) {
    if (d.size() % 2 == 0) {
      cout << d.back() << '\n';
      d.pop_back();
    } else {
      cout << d.front() << '\n';
      d.pop_front();
    }
  }
}

// Priority Queues
void priorityQueues() {
  /*
    Priority Queues are a data structure in which elements that enter are sorted
    so the biggest element is always the first to exit.
  */
  priority_queue<int> pq;

  /*
    IMPORTANT: Adding or removing elements from a priority queue has a O(log n)
    complexity due to the sorting operation.
  */
  pq.push(5);  // pq: 5
  pq.push(10); // pq: 10 5
  pq.push(20); // pq: 20 10 5
  pq.push(4);  // pq: 20 10 5 4
  pq.push(-1); // pq: 20 10 5 4 -1

  // Outputs the biggest element in the priority queue: 20.
  cout << pq.top() << '\n';
  // Gets the size of the priority queue.
  cout << pq.size() << '\n';
  // Returns true if the priority queue is empty.
  cout << pq.empty() << '\n';
  cout << '\n';

  pq.pop(); // pq: 10 5 4 -1. Removing elements from a priority queue has O(1)
            // time complexity.

  cout << pq.top() << '\n'; // 10
  cout << '\n';

  /*
    If we want to loop through the elements of a priority queue we can do the
    following.
  */
  while (!pq.empty()) {
    int currentValue = pq.top();

    cout << currentValue << '\n';

    pq.pop();
  }
}

// Sets, multisets and the unordered variant
void sets() {
  /*
    Sets are a data structures that stores unique values and let's us to
    efficiently do a look up of them. Sets won't store duplicates.
  */

  set<int> s;

  // Inserting or deleting elements in a set is an O(log n) operation.
  s.insert(4);
  s.insert(4);
  s.insert(4);
  s.insert(3);
  s.insert(-2);
  s.insert(-10);
  s.erase(-10);

  // Looking up elements in a set is also a O(log n) operation.
  cout << s.count(4) << '\n'; // 1
  cout << s.count(1) << '\n'; // 0

  /*
    Sets also have lower bound and upper bound operations, these two are O(log
    n) operations:
  */

  // Lower Bound will find an element not less than the one specified.
  cout << *s.lower_bound(3) << '\n'; // 3

  // Upper Bound will find an element greater than the one specified.
  cout << *s.upper_bound(3) << '\n'; // 4

  // There are other useful methods such as:
  cout << s.size() << ' ' << s.empty() << '\n';

  // Clearing the set is an O(n) operation.
  s.clear();

  cout << '\n';

  /*
    Multisets are very similar to sets with one main difference, multisets store
    duplicates of the same element.
  */
  multiset<int> ms;

  ms.insert(10);
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);

  cout << ms.count(10) << '\n'; // 5
  cout << '\n';

  /*
    Adding the unordered_ prefix to sets and multisets we get sets and multisets
    that don't perform an inner sorting ordering operation.
  */
  unordered_set<int> us;

  // Worst case scenario now becomes O(n) for these operations.
  us.insert(4);
  us.erase(4);
  cout << us.count(4) << '\n';
  cout << '\n';

  /*
    If we want to iterate through a set we'll have to use pointers or do a
    foreach loop.
  */

  s = {1, 5, 3, 4, 9, 4, 2};

  for (auto it = s.begin(); it != s.end(); it++) {
    if (it != s.begin())
      cout << ' ';
    cout << *it;
  }
  cout << '\n';

  for (int v : s) {
    cout << v << ' ';
  }
  cout << '\n';
}

// Maps, multimaps and the unordered variant
void maps() {
  /*
    Maps are data structures in which you can assign a custom key a value.
    The first type passed in will be the type of the key, the second type will
    be the type of the value contained for that key.
  */
  map<string, int> m;

  // Element insertion, deletion and access are O(log n) operations.
  m["hello"] = 42;
  m.insert({"goodbye", 24});

  cout << m["hello"] << ' ' << m["goodbye"] << '\n'; // 42 24

  m.erase("hello");

  /*
    If a non-declared or erased element is accessed and this element doesn't
    have a value, a default value will be assigned for that key.
  */
  cout << m["hello"] << '\n'; // 0

  // You can also get the size of the map and check if it's empty:
  cout << m.size() << ' ' << m.empty() << '\n';
  cout << '\n';

  /*
    Multimaps is what multisets are to sets, they can store multiple elements
    under the same key.
  */

  multimap<string, int> mm;

  /*
    Another difference between maps and multimaps is that we cannot directly
    access the key values, as them might be duplicated.
  */
  mm.insert({"hello", 32});
  mm.insert({"hello", 30});
  mm.insert({"hello", 31});

  mm.insert({"see you", 29});
  mm.insert({"see you", 28});

  /*
    To access them we'll either need to use pointers or do a foreach loop.
    In each iteration we will receive a pair object, its first attribute
    will be the key and the second the value for that key.
  */
  for (auto v : mm) {
    cout << v.first << ' ' << v.second << '\n';
  }

  /*
    Like with multisets, erasing a key will erase all its instances in the
    multimap.
  */
  mm.erase("see you");

  for (auto v : mm) {
    cout << v.first << ' ' << v.second << '\n';
  }
  cout << '\n';

  /*
    Unordered maps and unordered multimaps very similarly to sets make the
    insertion, deletion and access of values O(n) at the worst case scenario.
  */
}

// Pairs
void pairs() {
  /*
    Pairs are two values grouped together.
  */

  pair<int, int> p;
  pair<int, bool> p1 = make_pair(64, true);
  pair<string, float> p2 = {"hi", 4.2};

  // To access pair values we access the first and second attributes.
  p.first = 5;
  p.second = 10;

  cout << p1.first << ' ' << p1.second << '\n';
  cout << p2.first << ' ' << p2.second << '\n';

  cout << '\n';

  /*
    When comparing pairs it will first compare the two first elements, if the
    firsts are equal, then it will compare the seconds.
  */

  pair<int, int> pa = {1, 2}, pb = {2, 1}, pc = {2, 4}, pd = {1, 2};
  cout << (pa < pb) << ' ' << (pb < pc) << ' ' << (pa == pd) << '\n'; // 1 1 1
}

// Structs
void structs() {
  /*
    Structs are useful custom data structures that can be used to ease
    performing certain operations.
  */
  struct Element { // Normally we would declare these in the global scope, but
                   // for the sake of learning, we'll declare them in within
                   // this function
    int a, b, c;
  };

  /*
    When creating struct objects in this manner the order in which we declare
    the values will be the same order in which we will introduce them
  */
  Element element = {1, 2, 4};
  cout << element.a << ' ' << element.b << ' ' << element.c << '\n';

  // One use we could give structs is to make custom sorting.
  struct Number {
    int value, position;

    /*
      Here we declare the behavior we want when comparing against other struct
      of the same type using the < operator, this is needed if we want to sort
      using the function provided by STL. Also this specific operator is needed
      if we want to use this struct in data structures that involve any kind of
      internal ordering such as set and priority_queue.
    */
    bool operator<(Number &other) { return value < other.value; }
  };

  /*
    If we want to sort elements by value and retain their position we can do the
    following
  */
  vector<int> a = {5, 3, 9, 2, 1, 10};
  vector<Number> numbers;

  for (int i = 0; i < (int)a.size(); i++) {
    numbers.push_back({a[i], i});
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < (int)numbers.size(); i++) {
    cout << numbers[i].value << ' ' << numbers[i].position << '\n';
  }
}

// Useful STL Algorithms
void usefulSTLAlgorithms() {
  /*
    The Standard Library provides several functions that implement useful
    algorithms.
  */

  // Sort (O(n * log n))

  vector<int> a = {9, 4, 8, 2, 1, 0};

  sort(a.begin(), a.end());

  for (int v : a) {
    cout << v << ' '; // 0 1 2 4 8 9
  }
  cout << '\n' << '\n';

  // Max / Min

  cout << max(5, 20) << ' ' << min(15, 5) << '\n' << '\n'; // 20 5

  // Reverse elements (O(n))

  reverse(a.begin(), a.end());

  for (int v : a) {
    cout << v << ' '; // 9 8 4 2 1 0
  }
  cout << '\n' << '\n';

  // Find (O(n))

  auto it = find(a.begin(), a.end(), 8);
  cout << *it << '\n' << '\n'; // 8

  // Binary Search (O(log n))
  // needs the container of the elements to be sorted beforehand

  sort(a.begin(), a.end());

  bool found4 = binary_search(a.begin(), a.end(), 4);
  bool found404 = binary_search(a.begin(), a.end(), 404);

  cout << found4 << ' ' << found404 << '\n' << '\n'; // 1 0

  // Upper bound and lower bound O(log(n))
  // Requires the container to be sorted

  auto lowerBound = lower_bound(a.begin(), a.end(), 4);
  auto upperBound = upper_bound(a.begin(), a.end(), 4);

  cout << *lowerBound << ' ' << *upperBound << '\n' << '\n'; // 4 8

  // Swap (O(n) if used in arrays)

  int x = 10, y = 20;
  swap(x, y);

  cout << x << ' ' << y << '\n' << '\n'; // 20 10

  // Max Element / Min Element (O(n))
  // Gets the maximum/minimum element out of a container of elements

  auto minElementPtr = min_element(a.begin(), a.end());
  auto maxElementPtr = max_element(a.begin(), a.end());

  cout << *maxElementPtr << ' ' << *minElementPtr << '\n' << '\n'; // 9 0

  // Accumulate O(n)

  int sum = accumulate(a.begin(), a.end(), 0);
  int product = accumulate(a.begin() + 1, a.end(), 1, multiplies<int>());

  cout << sum << ' ' << product << '\n' << '\n';

  // Fill (O(n))

  fill(a.begin(), a.end(), 100);
  for (int v : a) {
    cout << v << ' '; // 100 100 100 100 100 100
  }
}

main() {
  // Call the functions here to see the contents in action.
}