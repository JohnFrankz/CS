def fact(n):
    """compute n factorial

    >>> fact(4)
    24
    >>> fact(1)
    1
    """
    if n == 1:
        return 1
    else:
        return fact(n -1) * n
        