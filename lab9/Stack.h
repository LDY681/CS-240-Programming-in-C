// Make sure that this file is included only once
#ifndef Stack_h
#define Stack_h

// Definition of a Stack class to store double values

class Stack {
 private:
	int maxStack;   // Max number of elements
	int top;        // Index to top of the stack
	double * stack; // Stack array
 public:
	// Constructor
	Stack(int maxStack);

	// Push a value into the stack.
	// Return false if max is reached.
	bool push(double value);

	// Pop a value from the stack.
	// Return false if stack is empty
	bool pop(double & value);

	// Return number of values in the stack
	int getTop() const;

	// Return max number of values in stack
	int getMaxStack() const;

	// Prints the stack contents
	void print() const;

  // Destructor
  ~Stack();
};

#endif

