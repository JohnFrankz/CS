from math import gcd

def rational(numerator, denominator):
    greatest_common_denomin = gcd(numerator, denominator)
    return pair(numerator // greatest_common_denomin, denominator // greatest_common_denomin)

def numer(x):
    return x(0)

def denomin(x):
    return x(1)

def add_rationals(x, y):
    numer_x, denomin_x = numer(x), denomin(x)
    numer_y, denomin_y = numer(x), denomin(y)
    return rational(numer_x * denomin_y + numer_y * denomin_x, denomin_x * denomin_y)

def mul_rationals(x, y):
    return  rational(numer(x) * numer(y), denomin(x) * denomin(y))

def print_rational(x):
    print(numer(x), '/', denomin(x))

def pair(x, y):
    def get(index):
        if index == 0:
            return x 
        elif index == 1:
            return y 
    return get

def select(p, i):
    return p(i)


# def add_rationals(x, y):
#     numer_x, denomin_x = numer(x), denomin(x)
#     numer_y, denomin_y = numer(y), denomin(y)
#     return rational(numer_x * denomin_y + numer_y * denomin_x, denomin_y * denomin_x)

# def mul_rationals(x, y):
#     return rational(numer_x * numer_y, denomin_x * denomin_y)

# def pair(x, y):
#     def select(n):
#         if n == 0:
#             return x 
#         elif n == 1:
#             return y 
#     return select

# def numer(p):
#     return p(0)

# def denomin(p):
#     return p(1)

# def rational(n, d)
#     greatest_common_denomin = gcd(n, d)
#     return pair(n // greatest_common_denomin, d // greatest_common_denomin )