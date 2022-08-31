from 

def divisors(n):
    return [1] + [x for x in range(2, n) if n % x == 0]

def perfect_number_below_n(n):
     return [x for x in range(1, n) if sum(divisors(x)) == x]

def width(area, height):
    assert area % height == 0
    return area // height

def perimeter(width, height):
    return 2 * (width + height)

def min_perimeter(area):
    heights = divisors(area)
    perimeter_list = [perimeter(width(area, height), height)for height in heights]
    return min(perimeter_list)
