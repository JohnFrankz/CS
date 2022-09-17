def dictionary():
    """Return a functional implementation of a dictionary."""
    recodes = []
    def getitem(key):
        matches = [r for r in recodes if r[0] == key]
        if len(matches) == 1:
            key, value = matches[0]
            return value
    
    def setitem(key,value):
        nonlocal recodes
        non_matched = [r for r in recodes if r[0] != key]
        recodes = non_matched + [[key, value]]

    def dispatch(message, key = None, value = None):
        if message == 'getitem':
            return getitem(key)
        elif message == 'setitem':
            setitem(key, value)
    return dispatch