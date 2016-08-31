/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *      Basic OSX message box sample -
 *        Version:  1.0
 *        Created:  26/03/2012 15:37:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "Apple.h"

int message_box(const char *title,const char *message);

int main(int argc, const char** argv)
{
    return message_box("Core Foundation", "Fuck Coca");
}

int message_box(const char *title,const char *message)
{
    MacString msg_title(title);
    MacString msg_content(message);

    MacStringPair pair(msg_title,msg_content);

    MacDictionary dictionary(pair.dictionary(kCFUserNotificationAlertHeaderKey,kCFUserNotificationAlertMessageKey));

    MacDialog message_dialog(dictionary);

    return message_dialog.result();
}
