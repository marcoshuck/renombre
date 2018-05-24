#include "messagehelper.h"

void MessageHelper::Success(std::string message)
{
    std::cout << "[Success]" << " " << message << std::endl;
}

void MessageHelper::Debug(std::string message)
{
    std::cout << "[Debug]" << " " << message << std::endl;
}

void MessageHelper::Error(std::string message)
{
    std::cout << "[Error]" << " " << message << std::endl;
}

void MessageHelper::Warning(std::string message)
{
    std::cout << "[Warning]" << " " << message << std::endl;
}

void MessageHelper::Info(std::string message)
{
    std::cout << "[Info]" << " " << message << std::endl;
}
