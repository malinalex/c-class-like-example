This repo is a small reference example for a basic class implementation in C. The pattern is basic but still allows inheritance.

Usually I would use this for managing peripherals like sensors or motor controllers, this example uses fake "sensors" that do nothing but demonstrate the pattern.

The advantages of using this pattern...

- Allows class-like management when you either cannot or do not want to use C++

The disadvantages of using this pattern...

- Needing to pass "self" explicitly looks odd and can be confusing for people not used to the pattern
- Since the pattern relies heavily on the method args casting from void this pattern requires use of an SCA tool to ensure type safety
