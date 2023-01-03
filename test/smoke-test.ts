import { getUserLocale } from '../lib/'

describe('getUserLocale', () => {
  it('works', () => {
    if (process.platform === 'win32') {
      const locale = getUserLocale()
      expect(locale).not.toBeUndefined()
      expect(typeof locale).toBe('string')
      // expect(locale).toEqual('h:mm:ss tt')
      expect(locale).toMatch(/h:mm:ss tt|HH:mm:ss/)
    }
  })
})
