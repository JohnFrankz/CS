odds = [1, 3, 5, 7, 9]

print([x + 1 for x in odds])
print([x for x in odds if 25 % x == 0])

def divisors(n):
    """

    >>> divisors(4)
    [1, 2]
    >>> divisors(8)
    [1, 2, 4]
    """
    return [1] + [x for x in range(2, n) if n % x == 0]