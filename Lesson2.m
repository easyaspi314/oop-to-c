@import CoreFoundation;

@interface Lesson2Base : NSObject {
    int a;
}
- (instancetype) init;
- (void) DoSomething;

@end

@interface Lesson2 : Lesson2Base {
    int b;
}
- (instancetype) init;
- (void) DoSomething;
@end

@implementation Lesson1Base
- (instancetype) init {
    if (self = [super init])
        NSLog(@"    Lesson2Base ctor called!\n");
    return self;
}

- (void) DoSomething {
    NSLog(@"    Lesson2Base DoSomething called!\n");
}
@end

@implementation Lesson2
- (instancetype) init {
    if (self = [super init])
        NSLog(@"    Lesson2 ctor called!\n");
    return self;
}

- (void) DoSomething {
    NSLog(@"    Lesson2 DoSomethingElse called!\n");
}
@end

int main()
{
    NSLog(@"Lesson2:");
    Lesson2 *l2 = [[Lesson2 alloc] init];
    NSLog(@"call DoSomething:");
    [l2 DoSomething];
    NSLog(@"Cast to base: The same function is called:");
    [(Lesson2Base *)l2 DoSomething];
    [l2 release];

    NSLog(@"Lesson2:");
    Lesson2Base *l2b = [[Lesson2Base alloc] init];
    NSLog(@"call DoSomething:");
    [l2b DoSomething];
    [l2 release];

    return 0;
}
