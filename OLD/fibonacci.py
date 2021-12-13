def fib(num):
    if num <= 1:
        return num
    else:
        return fib(num - 1) + fib(num - 2)


def fib_fast(num):
    arr = [0, 1]
    for i in range(2, 100000):
        next = arr[i - 1] + arr[i - 2]
        arr.append(next)
    return arr[num]


print(fib_fast(12))
