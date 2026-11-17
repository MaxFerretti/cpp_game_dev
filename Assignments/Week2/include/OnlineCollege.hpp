#pragma once

#include "College.hpp"

class OnlineCollege : public College
{
    protected:
        std::string m_platform_url; // The online platform used by the online college

    public:
        OnlineCollege(const std::string& name, const std::string& platform_url);
        
        std::string getPlatformUrl() const;
};