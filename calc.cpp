#include "calc.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using std::stringstream;
using std::vector; using std::map;
using std::string;
using std::cout; using std::endl;
struct Calc {
};

class CalcImpl : public Calc {
  public:
    map<string, int> vars;
    
    // Member Functions
    int evalExpr(const char *expr, int &result);




};

// constructor for calculator object
extern "C" struct Calc *calc_create(void) {
  return new CalcImpl();
}

// Destructor for calculator object
extern "C" void calc_destroy(struct Calc *calc) {
  CalcImpl *obj = static_cast<CalcImpl *>(calc);
  delete obj;
}

// Compute an evaluation given a calculator object, and expression. 
// Store the result in a pointer to result
extern "C" int calc_eval(struct Calc *calc, const char *expr, int *result) {
  CalcImpl *obj = static_cast<CalcImpl *>(calc);
  return obj->evalExpr(expr, *result);
}

// Split an expression into tokens
vector<string> tokenize(const char *expr) {
  vector<string> vec;
  stringstream s(expr);

  string tok;
  while (s >> tok) {
    vec.push_back(tok);
  }

  return vec;
}

// Given an expression, calculate its result and return it
int CalcImpl::evalExpr(const char *expr, int &result) {
  vector<string> parsed_expr = tokenize(expr);
  result = atoi(const_cast<char*> (parsed_expr[0].c_str()));
  
  //result = atoi(parsed_expr[0]);
  return result;
  //int size = int(parsed_expr.size());
  //result = size;
  
  //result = atoi(const_cast<char*>(parsed_expr[2].c_str()));
  

/*  
  // handle variable assignment
  if (std::find(parsed_expr.begin(), parsed_expr.end(), "=") != parsed_expr.end()) {
    string var = parsed_expr[0];
    
    // evaluate expression following declaration
    result = atoi(const_cast<char*>(parsed_expr[2].c_str()));

    // declare and set iterator to variable name input
    map<string, int>::iterator itr;
    itr = this->vars.find(var);
   
    // update variable entry or create new one if it doesn't exist
    if (itr != this->vars.end()) {
      itr->second = result;
    } else {
      this->vars.insert({var, result});
    }
    cout << vars[var] << endl;
  }
  //result = atoi(expr);
*/
  //return result;
}

// Add integer x and integer y
int add(int x, int y) {
  return x + y;
}

// Subtract integer y from integer x
int sub(int x, int y) {
  return x - y;
}

// Multiply integer x by integer y
int mult(int x, int y) {
return x*y;
}

// Divide integer x by integer y
int divide(int x, int y) {
 return x / y;
}







