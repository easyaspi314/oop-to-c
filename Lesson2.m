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
        NSLog(@"Lesson2Base ctor");
    return self;
}

- (void) DoSomething {
    NSLog(@"Lesson2Base DoSomething");
}
@end

@implementation Lesson2
- (instancetype) init {
    if (self = [super init])
        NSLog(@"Lesson2 ctor");
    return self;
}

- (void) DoSomething {
    NSLog(@"Lesson2 DoSomethingElse");
}
@end

int main()
{
    Lesson2 *l2 = [[Lesson2 alloc] init];
    [l2 DoSomething];
    [l2 release];

    Lesson2Base *l2b = [[Lesson2Base alloc] init];
    [l2b DoSomething];
    [l2 release];

    return 0;
}
