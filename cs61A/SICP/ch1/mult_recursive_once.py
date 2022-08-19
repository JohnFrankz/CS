def play_Alice(n):
    """
    >>> play_Alice(20)
    Bob wins
    """
    if n == 0:
        print("Bob wins")
    else:
        play_Bob(n - 1)

def play_Bob(n):
    if n == 0:
        print("Alice wins")
    elif n % 2 == 0:
        play_Alice(n - 2)
    else:
        play_Alice(n - 1)