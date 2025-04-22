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
  * E1 -> m % n => r < n
  * E2 ->   (1): m = n
  *         (2): n = r => n gets reduced since r < n => n_New < n_Old
  *         (1) ^ (2) => m > n
  * E1 -> m % n where m > n
  */