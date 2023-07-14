import { is24hoursTimeFormat, getUserDefaultLocaleName } from '../lib/'

describe('getUserLocale', () => {
  it('test is24HoursTimeFormat', () => {
    if (process.platform === 'win32') {
      const locale = is24hoursTimeFormat()
      expect(locale).not.toBeUndefined()
      console.log(locale)
      expect(typeof locale).toBe('boolean')
    }
    if (process.platform === 'darwin') {
      const locale = is24hoursTimeFormat()
      expect(locale).not.toBeUndefined()
      console.log(locale)
      expect(typeof locale).toBe('boolean')
    }
  })

  it('test getUserDefaultLocaleName ', () => {
    if (process.platform === 'win32') {
      const localeName = getUserDefaultLocaleName()
      expect(localeName).not.toBeUndefined()
      console.log(localeName)
      expect(typeof localeName).toBe('string')
    }
    if (process.platform === 'darwin') {
      const locale = getUserDefaultLocaleName()
      expect(locale).not.toBeUndefined()
      console.log(locale)
      expect(typeof locale).toBe('string')
    }
  })
})
