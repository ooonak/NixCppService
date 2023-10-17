#pragma once

#include "spdlog/spdlog.h"
#include <memory>
#include <string>

namespace CppService {
class ServiceImpl
{
public:
  explicit ServiceImpl(std::shared_ptr<spdlog::logger> logger);

  ~ServiceImpl();

  std::string sayHello(const std::string &name) const;

private:
  std::shared_ptr<spdlog::logger> logger_;
};

} // namespace CppService