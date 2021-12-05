
def NaiveGCD(a, b):
    gcd = 1
    for d in range(1, min(a, b) + 1):
        if (a % d == 0) and (b % d == 0):
            if d > gcd:
                gcd = d
    return gcd


def EuclidGCD(a, b):
    if b == 0:
        return a
    _a = a % b
    return EuclidGCD(b, _a)



print(EuclidGCD(357, 234))
