#include "../include/OnlineCollege.hpp"

OnlineCollege::OnlineCollege(const std::string& name, const std::string& platform)
    : College(std::move(name)), m_platform_url(std::move(platform))
{
}

std::string OnlineCollege::getPlatformUrl() const
{
    return m_platform_url;
}