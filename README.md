*This project has been created as part of the 42 curriculum by yboukhmi*

# **Description**
Push Swap is a sorting algorithm project. The goal is to sort a stack of numbers using a limited set of operations, with the smallest number of moves possible.
You have two stacks: stack A (which starts with random numbers) and stack B (which starts empty). You need to sort stack A in ascending order using specific operations like swap, push, and rotate.

This repository includes:

push_swap: The main program that calculates and outputs the most efficient sorting instructions.

checker: A bonus program that validates whether a list of instructions actually sorts the stack correctly.

# **Instructions**
To compile the project, run:
```
make
```
This will create the `push_swap` executable.

# **Usage**
Run the program with a list of numbers:
```
./push_swap 3 2 5 1 4
```
The program will output the list of operations needed to sort the numbers.

# **Available Operations**
- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: sa and sb at the same time
- `pa`: push the first element of B to A
- `pb`: push the first element of A to B
- `ra`: rotate stack A up (first element becomes last)
- `rb`: rotate stack B up
- `rr`: ra and rb at the same time
- `rra`: rotate stack A down (last element becomes first)
- `rrb`: rotate stack B down
- `rrr`: rra and rrb at the same time

# **Checker (Bonus)**

Start by :
```
make bonus
```

And then To run the Bonus part we use a so called pipe `|` :
```
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

# **Ressources**

- This is my push swap notion page, that i fully made, fully wrote :
https://www.notion.so/PUSH_SWAP-2bff054d95938006a66fd20acfb8db6d?source=copy_link
- Ai was a big part of learning linked lists, and how to correcty work with them:
https://gemini.google.com/
- And for sure 1337 peer learning

# **AI Usage**
AI was used in this project for:
- **Understanding algorithms**: Getting explanations of different sorting strategies and their complexity
- **AI was NOT used for**:
	- Writing the core algorithm implementation
	- Solving the main logic of the sorting problem

# **Features**
- Sorts any list of integers
- Handles edge cases (duplicate numbers, already sorted, etc.)
- Optimized to use minimal operations
- Error handling for invalid input