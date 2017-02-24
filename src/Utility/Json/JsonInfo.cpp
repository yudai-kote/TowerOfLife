#include "JsonInfo.h"
#include "cinder/app//App.h"

bool tol::JsonInfo::openJson(const std::string & file_name)
{
    return reader.parse(
        static_cast<const char*>(
            ci::app::loadAsset(file_name)->getBuffer().getData()),
        root);
}

bool tol::JsonInfo::isValue(const Json::Value & value)
{
    return (value.isNull() || value.isObject());
}

Json::Value tol::JsonInfo::getValue(const std::string & key, const Json::Value & value)
{
    return value.get(key, value);
}
