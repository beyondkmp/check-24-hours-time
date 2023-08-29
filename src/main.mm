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

   [formatter release];  // Release the NSDateFormatter instance
   
   return Napi::Value::From(info.Env(), is24h);
}

Napi::String getUserDefaultLocaleName(const Napi::CallbackInfo &info)
{
  NSLocale *locale = [NSLocale currentLocale];
  NSString *localeIdentifier = [locale localeIdentifier];

  // Convert NSString to std::string
  const char *cStr = [localeIdentifier UTF8String];
  std::string stdStr(cStr);
  
  return Napi::String::New(info.Env(), stdStr);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "is24hoursTimeFormat"), Napi::Function::New(env, is24hoursTimeFormat));
    exports.Set(Napi::String::New(env, "getUserDefaultLocaleName"), Napi::Function::New(env, getUserDefaultLocaleName));
    return exports;
}

#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(check24HoursTimeModule, Init)
#else
NODE_API_MODULE(check24HoursTimeModule, Init);
#endif