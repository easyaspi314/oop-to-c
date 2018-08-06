@import CoreFoundation;

@interface Lesson1 : NSObject
{
    int x;
}

+ (void) DoSomethingElse;
- (void) DoSomething: (int) value;

@end

@implementation Lesson1

+ (void) DoSomethingElse
{
    NSLog(@"DoSomethingElse");
}

- (void) DoSomething : (int) value
{
    [self x] = value;
    NSLog(@"x is %d", [self x]);
    [self DoSomethingElse];
}

@end

int main()
{
    Lesson1 *obj = [[Lesson1 alloc] init];

    [obj DoSomething:value:4];
    [obj release];
}

