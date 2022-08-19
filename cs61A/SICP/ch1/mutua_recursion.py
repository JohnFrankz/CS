def is_even(n):
    """
    >>> is_even(4)
    True
    """
    if n == 0:
        return True
    else:
        return is_odd(n - 1)

def is_odd(n):
    """
    >>> is_odd(3)
    True
    """
    if n == 0:
        return False
    else:
        return is_even(n - 1)

def is_even_single(n):
    """
    >>> is_even_single(4)
    True
    >>> is_even_single(100)
    True
    >>> is_even_single(77)
    False
    """
    if n == 0:
        return True
    elif n - 1 == 0:
        return False
    else:
        return is_even(n - 2)