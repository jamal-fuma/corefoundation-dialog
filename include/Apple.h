/*
 * =====================================================================================
 *
 *       Filename:  Apple.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2012 11:53:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <CoreFoundation/CoreFoundation.h>
class MacString
{
public:
    MacString(const char *str) :
        m_value(CFStringCreateWithCString(kCFAllocatorDefault, str,kCFStringEncodingMacRoman) ) { }

    CFStringRef value() const {
        return m_value;
    }

    ~MacString() {
        CFRelease(m_value);
    }
private:
    CFStringRef m_value;
};

class MacDictionary
{
public:
    MacDictionary(CFDictionaryRef dict) :
        m_dict(dict) {}

    CFDictionaryRef reference() const {
        return m_dict;
    }

    ~MacDictionary() {
        CFRelease(m_dict);
    }
private:
    CFDictionaryRef m_dict;
};

class MacDialog
{
public:
    MacDialog(const MacDictionary & dictionary) :
        m_result(0) {
        m_dialog = CFUserNotificationCreate(
                kCFAllocatorDefault,
                0,
                kCFUserNotificationPlainAlertLevel,
                &m_result,
                dictionary.reference()
                );
    }

    int result() const {
        return m_result;
    }

    ~MacDialog() {
        CFRelease(m_dialog);
    }

private:
    CFUserNotificationRef m_dialog;
    SInt32                m_result;
};

class MacStringPair
{
    public:
        MacStringPair(const MacString & first, const MacString & second) :
            m_first(first),
            m_second(second) {}

        CFDictionaryRef dictionary(const void *first_key, const void *second_key){
            const void* vals[] = { m_first.value(), m_second.value() };
            const void* keys[] = { first_key, second_key };

            return CFDictionaryCreate(0,
                    keys,
                    vals,
                    2,
                    &kCFTypeDictionaryKeyCallBacks,
                    &kCFTypeDictionaryValueCallBacks
                    );
        }
        ~MacStringPair() {
        }
    private:
        const MacString & m_first;
        const MacString & m_second;
};
