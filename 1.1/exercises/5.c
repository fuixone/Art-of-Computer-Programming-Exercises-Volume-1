/**
 * Exercise 5 of 1.1
 * 
 * [12] Show that the "Procedure for Reading this Set of Books" that 
 * appears in the preface actually fails to be a genuine algorithm 
 * on three of our five counts! Also mention some differences in
 * format between it and Algorithm E 
 */

 /**
  * Particularily it fails on:
  * 1) Definiteness - For example, in step 14, what is "tired" ? 
  *                     How can this be defined exactly? It can't.
  * 2) Finiteness - The last step, says we should go back to step 3
  *                 creating an infinite loop
  * 3) Output - There is no output. You could argue your "skill" is the output
  *                but I think this is the 3rd that violates the definition
  *                 of an algorithm.
  * 
  * Some differences in FORMAT:
  *     - There's a lot more conditional jumps
  *     - There's a lot of recursion(as opposed to "one" or zero recursion in Euclidean)
  */