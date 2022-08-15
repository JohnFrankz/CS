def sum_digits(n):
    """
    Return the sum of the digits of positive integer n.

    >>> sum_digits(18117)
    18
    >>> sum_digits(9)
    9
    """
    if n < 10:
        return n
    else:
        all_but_last, last = n // 10, n % 10
        return sum_digits(all_but_last) + last