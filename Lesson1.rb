#!/usr/bin/env ruby
# frozen_string_literals: true

class Lesson1
    @@x = 0
    def initialize(x = 0)
        @x = x
    end

    def DoSomethingElse
        puts 'DoSomethingElse'
    end

    def DoSomething(value)
        @x = value
        puts "x is equal to #{@x}"
        DoSomethingElse()
    end
end

obj = Lesson1.new
obj.DoSomething 4
