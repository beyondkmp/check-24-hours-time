#include <napi.h>
#include <windows.h>

Napi::Value is24hoursTimeFormat(const Napi::CallbackInfo &info)
{
  wchar_t format[80]; // 80 is always enough
  bool is24Hours = false;

  int ret = GetLocaleInfoEx(
      LOCALE_NAME_USER_DEFAULT,
      LOCALE_SSHORTTIME,
      format,
      sizeof(format) / sizeof(*format));
  if (ret != 0 && format[0] == 'H')
  {
    is24Hours = true;
  }
  return Napi::Value::From(info.Env(), is24Hours);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "is24hoursTimeFormat"), Napi::Function::New(env, is24hoursTimeFormat));
  return exports;
}
#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(check24HoursTimeModule, Init)
#else
NODE_API_MODULE(check24HoursTimeModule, Init);
#endif