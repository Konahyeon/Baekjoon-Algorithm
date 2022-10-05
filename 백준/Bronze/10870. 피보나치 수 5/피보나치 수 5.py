def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

a = (int)(input())
print(fibonacci(a))