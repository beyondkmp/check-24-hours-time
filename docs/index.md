# Documentation

## API

```typescript
import { getUserLocale } from 'beyondkmp/win32-user-locale'

// getUserLocale returns 'h:mm:ss tt' if system time is 12 hours. returns 'HH:mm:ss' if 24 hours
// return undefine if GetLocaleInfoEx call fails
const locale = getUserLocale()
if (locale){
  locale[0] === 'h' && console.log('12 hours');
  locale[0] === 'H' && console.log('24 hours');
}
```

## Setup

```shellsession
$ git clone https://github.com/desktop/win32-user-locale
$ cd win32-user-locale
$ yarn
```

As this project builds a native module, you'll need these dependencies along
with a recent version of Node:

- [Python](https://www.python.org/downloads/windows/)
  - _Let Python install for all users and (customized install) and \_ensure the
    **Add python.exe to Path** option is selected._
- One of Visual Studio 2019, Visual C++ Build Tools or Visual Studio 2019
  - [Visual C++ Build Tools](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools)
    - _Run `npm config set msvs_version 2019` to tell node to use this
      toolchain._
  - [Visual Studio 2019](https://www.visualstudio.com/vs/community/)
    - _Ensure you select the **Desktop development with C++** feature as that is
      required by Node.js for installing native modules._
    - _Run `npm config set msvs_version 2019` to tell node to use this
      toolchain._
