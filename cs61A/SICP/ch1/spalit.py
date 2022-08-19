def split(n):
    """Return the last digit of n and all but its last digit."""
    return n % 10, n // 10

def sum_digits(n):
    if n < 10:
        return n
    else:
        last, all_but_last = split(n)
        return sum_digits(all_but_last) + last

def luhn_sum(n):
    if n < 10:
        return n
    else:
        last, all_but_last = split(n)
        return luhn_sum_double(all_but_last) + last

def luhn_sum_double(n):
    last, all_but_last = split(n)
    luhn_digit = sum_digits(2 * last)
    if n < 10:
        return luhn_digit
    else:
        return luhn_sum(all_but_last) + luhn_digit