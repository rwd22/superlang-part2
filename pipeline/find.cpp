
template<typename I, typename T>
I find(I first, I last, const T& value)
{
  while (first != last) {
    if (*first == value)
      return first;
    ++first;
  }
  return last;
}

int main() {
  int a[] = {6, 4, 42, 0, 1024, 1, -4, 12};
  int n = sizeof(a) / sizeof(int);
  int* p = find(a, a + n, 0);
  return p - a;
}

