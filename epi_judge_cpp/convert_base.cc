#include <string>

#include "test_framework/generic_test.h"
using std::string;

string ConvertBase(const string& num_as_string, int b1, int b2) {
  // TODO - you fill in here.
  int l = num_as_string.length();
  int x = 0;

  string sign = "";
  if (num_as_string[0] == '-'){
    sign = "-" + sign;
  }
  
  for (int i=0; i<l; i++) {
    char c = num_as_string[l-1-i];
    if (c == '-') {
      break;
    }
    if (c-'0' < 10){
      x += (c-'0') * (pow(b1, i));
    }
    else {
      int cc = c-65;
      x += (cc+10) * (pow(b1, i));
    }
  }
  
  string res = "";
  if (x == 0) res = "0" + res;
  while(x != 0) {
    int r = x%b2;
    string s;
    if (r < 10){
      s = std::to_string(r);
    }
    else {
      r = r-10;
      char num = r + 65;
      s = num;
    }
    res = s + res;
    x = x/b2;
  }
  return sign + res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  return GenericTestMain(args, "convert_base.cc", "convert_base.tsv",
                         &ConvertBase, DefaultComparator{}, param_names);
}
