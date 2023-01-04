import { is24hoursTimeFormat } from '../lib/'

describe('getUserLocale', () => {
  it('works', () => {
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
})
