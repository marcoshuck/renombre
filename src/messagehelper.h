#ifndef MESSAGEHELPER_H
#define MESSAGEHELPER_H

#include <iostream>
#include <string>

class MessageHelper
{
public:
    static void Success(std::string message);
    static void Debug(std::string message);
    static void Error(std::string message);
    static void Warning(std::string message);
    static void Info(std::string message);
};

#endif // MESSAGEHELPER_H
