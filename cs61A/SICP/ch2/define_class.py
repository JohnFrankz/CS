class Account:
    # A class attribute(or static variables).
    interest = 0.02
    def __init__(self, account_holder):
        self.balance = 0
        self.holder = account_holder

    def deposit(self, amount):
        """Increase the account blance by amount and return the new balance."""
        self.balance += amount
        return self.balance

    def withdraw(self, amount):
        if amount > self.balance:
            return 'Insufficient funds'
        self.balance -= amount
        return self.balance

class CheckingAccount(Account):
    """A bank account that charge for withdrawals."""
    withdraw_charge = 1
    interest = 0.01
    def withdraw(self, amount):
        return Account.withdraw(self, amount + self.withdraw_charge)

class SavingAccount(Account):
    deposit_charge = 2
    def deposit(self, amount):
        return Account.deposit(self, amount - self.deposit_charge)

class AsSeenOnTVAccount(SavingAccount, CheckingAccount):
    def __init__(self, account_holder):
        self.balance = 1
        self.holder = account_holder

# ck = CheckingAccount('sam')
# ck.deposit(10)
# ck.withdraw(5)
such_a_deal = AsSeenOnTVAccount('john')
