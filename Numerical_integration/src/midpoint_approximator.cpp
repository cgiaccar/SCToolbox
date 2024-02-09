#include "../include/midpoint_approximator.hpp"
#include "muparserx/mpParser.h"

using namespace mup;
using namespace sctoolbox;

MidpointApproximator::MidpointApproximator(const double a, const double b, const std::string f, const unsigned int n)
{
    this->a = a;
    this->b = b;
    this->f = f;
    this->n = n;
}

double MidpointApproximator::approximate_step(const double first, const double second) const
 {
     ParserX p;
     Value x_1((first + second) / 2);  // x_1 = (a+b)/2
     p.DefineVar("x", Variable(&x_1)); // x = x_1
     p.SetExpr(f);
     try
     {
         Value result_f = p.Eval();                  // Evaluate expression
         return (second - first) * (double)result_f; // Midpoint rule
     }
     catch (ParserError &e) // Avoid having to catch a ParserX-specific exception in main
     {
         throw std::invalid_argument("Invalid expression.");
     }
 }