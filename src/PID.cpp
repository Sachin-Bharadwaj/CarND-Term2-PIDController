#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  p_error = 0;
  i_error = 0;
  d_error = 0;
  cte_intg = 0;
  cte_prev = 0;
  
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;
}

void PID::UpdateError(double cte) {
  cte_intg += cte;
  p_error  = -Kp * cte;
  d_error  = -Kd * (cte - cte_prev);
  i_error  = -Ki * cte_intg;
  cte_prev = cte; 
}

double PID::TotalError() {
  return p_error + d_error + i_error;
}

