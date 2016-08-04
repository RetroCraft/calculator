#include <vector>
#include <string>
#include <algorithm>

using std::string;

bool in_array(const string &value, const std::vector<string> &array) {
  return std::find(array.begin(), array.end(), value) != array.end();
}
