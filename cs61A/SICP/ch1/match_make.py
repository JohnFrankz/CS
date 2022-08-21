def match_k(k):
    """ Return a function that checks if digits k apart match

    >>> match_k(2)(1010)
    True
    >>> match_k(2)(2010)
    False
    >>> match_k(1)(1010)
    False
    >>> match_k(1)(1)
    True
    >>> match_k(1)(2111111111111111)
    False
    >>> match_k(3)(123123)
    True
    >>> match_k(2)(123123)
    False
    """
    def match(n):
        last_k_digit = n % 10**k
        while n > 0:
            n = n // 10**k
            before_last_k_digit = n % 10**k
            if last_k_digit != before_last_k_digit:
                return False
            last_k_digit = before_last_k_digit
        return True
    return match