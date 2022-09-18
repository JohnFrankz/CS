test = True

# implement pair

def pair(x, y):
    """Return a function that represents pairs"""
    def get(index):
        if index == 0:
            return x
        elif index == 1:
            return y
    return get

def select(pair, i):
    """Return the element at index i of pair p.
    
    >>> p = pair(20, 14)
    >>> select(p, 0)
    20
    >>> select(p, 1)
    14
    """
    return pair(i)


# implement link
empty = 'empty'

def is_link(s):
    """s is a linked list if it is empty or a (first, rest) pair."""
    return s == empty or (len(s) == 2 and is_link(s[1]))

def link(first, rest):
    """Construct a linked list from its first element and the rest."""
    assert is_link(rest)
    return [first, rest]

def first(s):
    """Return the first element of a linked list s.

    >>> first(four)
    1
    """
    assert is_link(s)
    assert s != empty
    return s[0]

def rest(s):
    """Return the rest of the element of a linked list.
    
    >>> rest(four)
    [2, [3, [4, 'empty']]]
    """
    assert is_link(s)
    assert s != empty
    return s[1]

# Implemented recursively.
# def len_link(s):
#     if s == empty:
#         return 0
#     return 1 +len_link(rest(s))

def len_link(s):
    """Return the length of linked list s.
    >>> len_link(four)
    4
    """
    length = 0
    while s != empty:
        s, length = rest(s), length + 1
    return length

# Implemented recursively.
# def getitem_link(s, i):
#     if i = 0:
#         return first(s)
#     return getitem_link(rest(s), i - 1)

def getitem_link(s, i):
    """Return the element at the index i of linked list s.
    >>> getitem_link(four, 2)
    3
    """
    for _ in range(i):
        s = rest(s)
    return first(s)

def extend_link(s, t):
    """Return a list with the element of s followed by those of t.
    
    >>> extend_link(four, four)
    [1, [2, [3, [4, [1, [2, [3, [4, 'empty']]]]]]]]
    """
    assert is_link(s) and is_link(t)
    if s == empty:
        return t
    else:
        return link(first(s), extend_link(rest(s), t))

def apply_to_all_link(f, s):
    """Return f to each element of s.
    >>> apply_to_all_link(lambda x: x*x, four)
    [1, [4, [9, [16, 'empty']]]]
    """
    assert is_link(s)
    if s == empty:
        return s
    return link(f(first(s)), apply_to_all_link(f, rest(s)))

def keep_if_link(f, s):
    """Return a list with elements of s for which f(e) is true.
    
    >>> keep_if_link(lambda x: x%2 == 0, four)
    [2, [4, 'empty']]
    """
    assert is_link(s)
    if s == empty:
        return s
    else:
        keep = keep_if_link(f, rest(s))
        if f(first(s)):
            return link(first(s), keep)
        else:
            return keep
        
def join_link(s, separator):
    """Return a string of all element in s separated by spearator.
    
    >>> join_link(four, ", ")
    '1, 2, 3, 4'
    """
    if s == empty:
        return ""
    elif rest(s) == empty:
        return str(first(s))
    else:
        return str(first(s)) + separator + join_link(rest(s), separator)

def partitions(n, m):
    """Return a linked list of partitions of n using parts of up to m.
    Each partition is represented as a linked list.
    """
    if n == 0:
        # A list containing the empty partition
        return link(empty, empty)
    elif n < 0 or m == 0:
        return empty
    else:
        using_m = partitions(n - m, m)
        with_m =  apply_to_all_link(lambda s: link(m, s), using_m)
        without_m = partitions(n, m - 1)
        return extend_link(with_m, without_m)
    
def print_partitions(n, m):
    """
    >>> print_partitions(6, 4)
    4 + 2
    4 + 1 + 1
    3 + 3
    3 + 2 + 1
    3 + 1 + 1 + 1
    2 + 2 + 2
    2 + 2 + 1 + 1
    2 + 1 + 1 + 1 + 1
    1 + 1 + 1 + 1 + 1 + 1
    """
    lists = partitions(n, m)
    strings = apply_to_all_link(lambda s: join_link(s, " + "), lists)
    print(join_link(strings, "\n"))

def mutable_link():
    """Return a function implementation of a mutable linked list."""
    contents = empty
    def dispatch(message, value=None):
        nonlocal contents
        if message == 'len':
            return len_link(contents)
        elif message == 'getitem':
            return getitem_link(contents, index)
        elif message == 'push_first':
            contents = link(value, contents)
        elif message == 'pop_first':
            pop_element = first(contents)
            contents = rest(contents)
            return pop_element
        elif message == 'str':
            return join_link(contents, ", ")
    return dispatch

def to_mutable_link(source):
    """Return a functional list with the same contents as source.
    
    >>> s = to_mutable_link(suits)
    >>> type(s)
    <class 'function'>
    >>> print(s('str'))
    heart, diamond, spade, club
    >>> s('pop_first')
    'heart'
    >>> print(s('str'))
    diamond, spade, club
    """
    s = mutable_link()
    for element in reversed(source):
        s('push_first', element)
    return s

def dictionary():
    """Return a functional implementation of a dictionary.
    
    >>> d = dictionary()
    >>> d('setitem', 3, 9)
    >>> d('setitem', 4, 16)
    >>> d('getitem', 3)
    9
    >>> d('getitem', 4)
    16
    """
    records = []
    def getitem(key):
        matches = [r for r in records if r [0] == key]
        if len(matches) == 1:
            key, value = matches[0]
            return value
    def setitem(key, value):
        nonlocal records
        non_matches = [r for r in records if r[0] != key]
        records = non_matches + [[key, value]]
    def dispatch(message, key=None, value=None):
        if message == 'getitem':
            return getitem(key)
        elif message == 'setitem':
            setitem(key, value)
    return dispatch

if test:
    four = link(1, link(2, link(3, link(4, empty))))
    suits = ['heart', 'diamond', 'spade', 'club']
    print(suits)
    s = to_mutable_link(suits)
    # print_partitions(6, 4)
    # s = to_mutable_link(suits)