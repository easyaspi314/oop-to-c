#!/usr/bin/env python

from __future__ import print_function

class Lesson2Base(object):
    def __init__(self):
        print('    Lesson2Base ctor called!')
    @classmethod
    def DoSomething(self):
        print('    Lesson2Base DoSomething called!')

class Lesson2(Lesson2Base):
    def __init__(self):
        super(Lesson2Base, self).__init__()
        self.b = 0
        print('    Lesson2 ctor called!')
    @classmethod
    def DoSomething(self):
        print('    Lesson2 DoSomething called!')

print('Lesson2:');
l2 = Lesson2()
print('Call DoSomething')
l2.DoSomething()
print('(casting is weird in python and doesn\'t really apply here)')

print('Lesson2Base:')
l2b = Lesson2Base()
print('Call DoSomething')
l2b.DoSomething()

