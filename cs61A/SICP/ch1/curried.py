def curried(func):
    def f(x):
        def g(y):
            return func(x, y)
        return g
    return f

