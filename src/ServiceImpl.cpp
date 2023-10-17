#include "ServiceImpl.hpp"
#include "CppServiceConfig.hpp"

CppService::ServiceImpl::ServiceImpl(std::shared_ptr<spdlog::logger> logger) : logger_{logger}
{
  logger_->debug("{} version {}.{}.{}", __PRETTY_FUNCTION__, CppService_VERSION_MAJOR, CppService_VERSION_MINOR,
                 CppService_VERSION_PATCH);
}

CppService::ServiceImpl::~ServiceImpl() { logger_->debug(__PRETTY_FUNCTION__); }

std::string CppService::ServiceImpl::sayHello(const std::string &name) const
{
  return std::string("Hello ").append(name);
}
