# A list literal
Chinese = ['coin', 'string', 'myriad']

# Two names refer to thr same list
suit = Chinese

# Remove and return thee final element
print(suit.pop())


# Remove the first element that equals the argument
suit.remove('string')

# Add an element to the end
suit.append('cup')
# Add all element of a sequence to the end
suit.extend(['sword', 'club'])

# Italians called swords spades
suit[2] = 'spade'
print(suit)

# The French variant used today in the U.S. changes the first two suits:
suit[0:2] = ['heart', 'diamond']
print(suit)

# The name co-refers with "suit" to the same changing list
print(Chinese)

print('-----------------------------------------------------------------')
# Lists can be copied using list constructor function. Change to one list do not
# addect anther, unless they share structure
nest = list(suit)
nest[0] = suit
print(nest)

suit.insert(2, 'joker')
print(nest)

print(suit)
print(nest[0].pop(2))
print(suit)

print('-------------------------------')
# Python includes teo comparison opertors, called is and is not, that test 
# whether two expressions infact evaluate to the indentical object.
print(f'suit is nest[0]: {(suit is nest[0])}')
print('suit is nest[0]: ' + f'{(suit is nest[0])}')

print(f"{(suit is ['heart', 'diamond', 'spade', 'club'])}")
print(f"suit is ['heart', 'diamond', 'spade', 'club']: {(suit is ['heart', 'diamond', 'spade', 'club'])}")
print(f"suit is ['heart', 'diamond', 'spade', 'club']: %s" %(suit is ['heart', 'diamond', 'spade', 'club']))

print(f"suit == ['heart', 'diamond', 'spade', 'club']: {(suit == ['heart', 'diamond', 'spade', 'club'])}")

print("-------------------------------------------")
from unicodedata import lookup
print([lookup('WHITE ' + s.upper() + ' SUIT') for s in suit])