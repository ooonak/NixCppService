#include "cppservice/Service.hpp"
#include "ServiceImpl.hpp"

CppService::Service::Service(std::shared_ptr<spdlog::logger> logger) : impl_{std::make_unique<ServiceImpl>(logger)} {}

CppService::Service::~Service() {}

std::string CppService::Service::sayHello(const std::string &name) const { return impl_->sayHello(name); }
