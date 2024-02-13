#!/usr/bin/env python3


class Crop:
    def __init__(self, name, price):
        self.name = name
        self.price = int(price)
        self.computed_quantity = 0
    def __str__(self) -> str:
        if self.computed_quantity == 0:
            return f'{self.name}: 0 units at ${self.price}/unit'
        return \
            f'{self.name}: {self.computed_quantity:.2f} units at ${self.price}/unit'


class Fertilizer:
    def __init__(self, name, quantity):
        self.name = name
        self.quantity = quantity
    def __str__(self) -> str:
        return f'{self.quantity} {self.name}'
