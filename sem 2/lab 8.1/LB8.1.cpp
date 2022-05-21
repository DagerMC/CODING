#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
using std::array,
      std::cout, std::string;

template<class T, size_t n>
int minIndex(array<T, n>);

template<class T, size_t n>
T sum(array<T, n>);

template<class T, size_t n>
array<T, n> abs10(array<T, n>);

template<size_t n>
array<string, n> abs10(array<string, n>);

int main() {
  array<int, 10> arr {1, 5, -10, 3, 25, -100, -1, 9, 44, 2};
  array<string, 7> str{"i'm doing well.", "", "Hi ", "my dear ", "how are you?", "", "friend."};

  str = abs10(str);
  for (size_t i = 0; i < str.size(); i++) {
    cout << str[i] << " ";
  }

  cout << "\n";
  arr = abs10(arr);
    for (size_t i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  cout << "\n" << minIndex(arr)
       << " " << minIndex(str)
       << "\n" << sum(arr)
       << " " << sum(str);

  return 0;
}

template<class T, size_t n>
int minIndex(array<T, n> arr) {
  int index = 0;
  T min = arr[index];

  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] < min) {
      min = arr[i];
      index = i;
    }
  }

  return index;
}

template<class T, size_t n>
T sum(array<T, n> arr) {
  bool firstNeg = true;
  T sum = T();

  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] <= T()) {
      if (firstNeg) {
        firstNeg = false;
        continue;
      }

      break;
    }

    if (!firstNeg) {
      sum += arr[i];
    }
  }

  return sum;
}

template<class T, size_t n>
array<T, n> abs10(array<T, n> arr) {
  array<T, n> result;
  int index = 0;

  for (size_t i = 0; i < arr.size(); i++) {
    if (std::abs(arr[i]) < 10) {
      result[index] = arr[i];
      index++;
    }
  }

  for(size_t i = 0; i < arr.size(); i++) {
    if(std::abs(arr[i]) >= 10) {
      result[index] = arr[i];
      index++;
    }
  }

  return result;
}

template<size_t n>
array<string, n> abs10(array<string, n> arr) {
  array<string, n> result;
  int index = 0;

  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i].size() < 10) {
      result[index] = arr[i];
      index++;
    }
  }

  for(size_t i = 0; i < arr.size(); i++) {
    if(arr[i].size() >= 10) {
      result[index] = arr[i];
      index++;
    }
  }

  return result;
}


