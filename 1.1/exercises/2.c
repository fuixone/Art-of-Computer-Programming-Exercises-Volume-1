/**
 * Exercise 2 of 1.1
 * 
 * [15] Prove that m is always greater than n at the beginning of step
 * El, except possibly the first time this step occurs.
 */

 /**
  * Case m == n
  * 
  * E1 -> m % n => r = 0
  * E2 -> return n
  * 
  * Case m < n
  * E1 -> m % n => r = m
  * E3 ->   (1) m = n
  *         (2) n = r But r = m => n = m(the old one)
  * E3
  */