#include "cppservice/Service.hpp"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include <gtest/gtest.h>

TEST(Service, sayHello)
{
  CppService::Service service(spdlog::stdout_logger_mt("console"));
  EXPECT_EQ("Hello John", service.sayHello("John"));
}
