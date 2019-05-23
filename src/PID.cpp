#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialization PID coefficients (and errors)
   */
  
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  error_p = 0.0;
  error_i = 0.0;
  error_d = 0.0;

  // Previous cte
  cte_prev = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
   error_p = cte;
   error_d = cte - cte_prev;
   error_i += cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  
  return error_p * Kp + error_i * Ki + error_d * Kd;;  // TODO: Add your total error calc here!
}