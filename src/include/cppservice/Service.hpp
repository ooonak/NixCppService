#pragma once

#include "spdlog/spdlog.h"
#include <memory>
#include <string>

namespace CppService {
class ServiceImpl;

class Service
{
public:
  explicit Service(std::shared_ptr<spdlog::logger> logger);

  ~Service();

  std::string sayHello(const std::string &name) const;

private:
  std::unique_ptr<ServiceImpl> impl_;
};
} // namespace CppService
