#include <Logger.hpp>
#include <iostream>

Logger logger;

int main()
{
  logger.add_stream(std::cout);
  logger.add_file_stream(std::string(SOURCE_DIR_PATH) + "log/test.log");

  logger.info("starting chesspp v2.0");
  logger.info("chesspp v2.0 terminated successfully");
}