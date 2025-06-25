# fibonacci
def fibonacci(n):
  if n == 0:
    return 0
  if n == 1:
    return 1
  return fibonacci(n-1)+fibonacci(n-2)

#factorial
def factorial(n):
  if n==0 or n==1:
    return 1
  return n* factorial(n-1)

#sumOfNumbers
def sumOfNumbers(n):
  if n == 1:
    return 1
  return n + sumOfNumbers(n-1)

# ------------------MEMOIZATION--------------------------
#fibonacci
def MemoFibonacci(n, dp):
  if n == 0 :
    return 0
  if n == 1:
    return 1
  if dp[n] != -1:
    return dp[n]
  else:
    dp[n]= MemoFibonacci(n-1, dp) + MemoFibonacci(n-2, dp)
    return dp[n]

#Factorial
def MemoFactorial(n, dp):
  if n==0 or n==1:
    return 1
  if(dp[n] != -1):
    return dp[n]
  else:
    dp[n] = n*MemoFactorial(n-1, dp)
    return dp[n]

n = int(input())
print("Fibonacci of",n,"is",fibonacci(n))
print("Memoization Fibonacci of",n,"is",MemoFibonacci(n, dp=[-1]*(n+1)))

print("Factorial of",n,"is",factorial(n))
print("Memoization Factorial of",n,"is",MemoFactorial(n, dp=[-1]*(n+1)))

print("Sum upto",n,"is",sumOfNumbers(n))