//
//  JAPPMacro.h
//  JAppDevTools
//
//  Created by shupeng on 2019/5/10.
//  Copyright © 2019 shupeng. All rights reserved.
//

#ifndef JAPPMacro_h
#define JAPPMacro_h


// 日志
#ifdef DEBUG
#define LogDefault(_name_, ...) \
{ \
QMUILogItem *logItem = [QMUILogItem logItemWithLevel:QMUILogLevelDefault name:_name_ logString:__VA_ARGS__]; \
[[QMUILogger sharedInstance] printLogWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ logItem:logItem]; \
[QMUIConsole logWithLevel:@"Default" name:_name_ logString:[logItem logString]]; \
}

#define LogInfo(_name_, ...) \
{ \
QMUILogItem *logItem = [QMUILogItem logItemWithLevel:QMUILogLevelInfo name:_name_ logString:__VA_ARGS__]; \
[[QMUILogger sharedInstance] printLogWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ logItem:logItem]; \
[QMUIConsole logWithLevel:@"Info" name:_name_ logString:[logItem logString]]; \
}

#define LogWarning(_name_, ...) \
{ \
QMUILogItem *logItem = [QMUILogItem logItemWithLevel:QMUILogLevelWarn name:_name_ logString:__VA_ARGS__]; \
[[QMUILogger sharedInstance] printLogWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ logItem:logItem]; \
[QMUIConsole logWithLevel:@"Warning" name:_name_ logString:[logItem logString]]; \
}

#define LogError(_name_, ...) \
{ \
QMUILogItem *logItem = [QMUILogItem logItemWithLevel:QMUILogLevelWarn name:_name_ logString:__VA_ARGS__]; \
[[QMUILogger sharedInstance] printLogWithFile:__FILE__ line:__LINE__ func:__FUNCTION__ logItem:logItem]; \
[QMUIConsole logWithLevel:@"Error" name:_name_ logString:[logItem logString]]; \
}

#define NSLog(fmt, ...) LogDefault(@"APP", fmt, ##__VA_ARGS__)

#else
// 隐藏日志
#define LogDefault(_name_, ...)
#define LogInfo(_name_, ...)
#define LogWarning(_name_, ...)
#define LogError(_name_, ...)
#define NSLog(fmt, ...)
#endif


// 其他
#define LOC(title) NSLocalizedString(title, title)
#define STBD(name) [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:name]
#define XIBView(class, _owner) [[[NSBundle mainBundle] loadNibNamed:[class className] owner:_owner options:nil] firstObject]
#define XIBVC(class) [[class alloc] initWithNibName:[class className] bundle:nil]
#define NIB(class) [UINib nibWithNibName:[class className] bundle:nil]

#define EventName(class, name) [[class className] stringByAppendingString:name]
#endif /* JAPPMacro_h */
