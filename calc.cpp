#include "calc.h"
#include <vector>
#include <string>
#include <sstream>
using std::stringstream;
using std::vector;
using std::string;


struct Calc {
};

class CalcImpl : public Calc {
  public:
    

    int evalExpr(expr, *result);


  return 0;

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

vector<string> tokenize(const string &expr) {
  vector<string> vec;
  stringstream s(expr);

  string tok;
  while (s >> tok) {
    vec.push_back(tok);
  }

  return vec;
}

int evalExpr(const string &expr, int *result) {
  vector<string> parsed_expr = tokenize(expr);
  // do math?



  return result;
}
