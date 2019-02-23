#!/usr/bin/env ruby
# frozen_string_literals: true

class Lesson2Base
    def initialize()
        puts '    Lesson2Base ctor called!'
    end

    def DoSomething()
        puts '    Lesson2Base DoSomething called!'
    end
end

class Lesson2 < Lesson2Base
    @@b = 0
    def initialize()
        super
        @b = 0
        puts '    Lesson2 ctor called!'
    end

    def DoSomething()
        puts '    Lesson2 DoSomething called!'
    end
end
puts 'Lesson2:'
l2 = Lesson2.new()
puts 'Call DoSomething'
l2.DoSomething()
puts '(casting is weird in Ruby and doesn\'t really apply here)'

puts 'Lesson2Base:'
l2b = Lesson2Base.new()
puts 'Call DoSomething'
l2b.DoSomething()

