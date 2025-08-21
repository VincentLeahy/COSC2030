# Instructions  

Ackermann’s Function is a recursive mathematical algorithm that can be used to test how well a computer performs recursion. Write a function `A(m, n)` that solves Ackermann’s Function. Use the following logic in your function:

`If m = 0 then return n + 1`    
`If n = 0 then return A(m-1, 1)`    
`Otherwise, return A(m-1, A(m, n-1))`

Test your function in a driver program that displays the following values:

`A(0, 0) A(0, 1) A(1, 1) A(1, 2) A(1, 3) A(2, 2) A(3, 2)`