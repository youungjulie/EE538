
class CPPLib {
 public:
  // Write two functions for swapping variables:
  // See discussion 4: page 34, 35, 36
  // Example :
  // Before: x = 10, y = 15
  // We call Swap(x,y)
  // After: x = 15, y = 10

  void SwapByPointer(float *input1, float *input2);

  void SwapByReference(float &input1, float &input2);
};