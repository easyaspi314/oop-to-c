#!/usr/bin/env python

from __future__ import print_function

class Lesson1(object):
    def __init__(self, x = 0):
        self.x = x
    @staticmethod
    def DoSomethingElse():
        print('DoSomethingElse')
    @classmethod
    def DoSomething(self, value):
        self.x = value
        print('x is equal to {}'.format(self.x))
        Lesson1.DoSomethingElse()

obj = Lesson1()
obj.DoSomething(4)

