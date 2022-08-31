numerals = {'I': 1, 'V': 5, 'X': 10}

print(numerals['X'])
print(numerals.keys())
print(numerals.values())
print(numerals.items())
# 10
# dict_keys(['I', 'V', 'X'])
# dict_values([1, 5, 10])
# dict_items([('I', 1), ('V', 5), ('X', 10)])


items = [('I', 1), ('V', 5), ('X', 10)]
print(dict(items))
# {'I': 1, 'V': 5, 'X': 10}

print('X' in numerals)
print(numerals.get('X', False))
print(numerals.get('word', False))
# True
# 10
# False

print({x: x * x for x in range(10)})
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25, 6: 36, 7: 49, 8: 64, 9: 81}