#import <Foundation/Foundation.h>
#include <napi.h>

Napi::Value is24hoursTimeFormat(const Napi::CallbackInfo &info)
{
  NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
  [formatter setLocale:[NSLocale currentLocale]];
  [formatter setDateStyle:NSDateFormatterNoStyle];
  [formatter setTimeStyle:NSDateFormatterShortStyle];
  NSString *dateString = [formatter stringFromDate:[NSDate date]];
  NSRange amRange = [dateString rangeOfString:[formatter AMSymbol]];
  NSRange pmRange = [dateString rangeOfString:[formatter PMSymbol]];
  bool is24h = (amRange.location == NSNotFound && pmRange.location == NSNotFound);
  return Napi::Value::From(info.Env(), is24h);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "is24hoursTimeFormat"), Napi::Function::New(env, is24hoursTimeFormat));
  return exports;
}

#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(win32UserLocaleNativeModule, Init)
#else
NODE_API_MODULE(win32UserLocaleNativeModule, Init);
#endif