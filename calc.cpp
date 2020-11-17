#include "calc.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <stdlib.h>
using std::stringstream;
using std::vector; using std::map;
using std::string;

struct Calc {
};

class CalcImpl : public Calc {
  public:
    map<string, int> vars;
    
    // Member Functions
    int evalExpr(const char *expr, int &result);




};


extern "C" struct Calc *calc_create(void) {
  return new CalcImpl();
}

extern "C" void calc_destroy(struct Calc *calc) {
  CalcImpl *obj = static_cast<CalcImpl *>(calc);
  delete obj;
}

extern "C" int calc_eval(struct Calc *calc, const char *expr, int *result) {
  CalcImpl *obj = static_cast<CalcImpl *>(calc);
  return obj->evalExpr(expr, *result);
}

vector<string> tokenize(const char &expr) {
  vector<string> vec;
  stringstream s(expr);

  string tok;
  while (s >> tok) {
    vec.push_back(tok);
  }

  return vec;
}

int CalcImpl::evalExpr(const char *expr, int &result) {
  vector<string> parsed_expr = tokenize(*expr);
  string i = parsed_expr[0];
  string j = parsed_expr[1];
  std::cout << i << " " << j << std::endl;
  
  result = atoi(expr);

  return result;
}
