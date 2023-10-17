#include "cppservice/Service.hpp"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <iostream>

void setupLogging()
{
  spdlog::init_thread_pool(8192, 2);
  std::vector<spdlog::sink_ptr> sinks;
  auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  sinks.push_back(stdout_sink);

  auto serviceLogger = std::make_shared<spdlog::async_logger>(
      "Service", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
  serviceLogger->set_level(spdlog::level::level_enum::debug);
  spdlog::register_logger(serviceLogger);
}

int main()
{
  try {
    setupLogging();
    CppService::Service service(spdlog::get("Service"));
  } catch (const std::exception &exc) {
    std::cerr << exc.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
