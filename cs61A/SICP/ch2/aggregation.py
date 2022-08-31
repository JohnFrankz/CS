def apply_to_all(map_fn, s):
    """ apply_to_all are equivalent to python built-in map
    apply_to_all = lambda map_fn, s: list(map(map_fn, s))
    """
    return [map_fn(x) for x in s]

def keep_if(filter_fn, s):
    """ keep_if are equivalent to python built-in filter
    keep_if = lambda filter_in, s: list(filter(filter_fn, s))
    """
    return [x for x in s if filter_fn(x)]

def reduce(reduce_fn, s, initial):
    reduced = initial
    for element in s:
        reduced = reduce_fn(reduced, element)

        return reduced

def divisors_of(n):
    divides_n = lambda x: n % x == 0
    return [1] + keep_if(divides_n, range(2, n))

from operator import add

def sum_of_divisors(n):
    return sum(divisors_of(n))
    # return reduce(add, divisors_of, 0)

def perdext(n):
    return sum_of_divisors == n
