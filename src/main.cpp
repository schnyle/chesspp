#include <Logger.hpp>

Logger logger(std::string(SOURCE_DIR_PATH) + "log/test.log");

int main()
{
  logger.info("starting chesspp v2.0");
  logger.info("chesspp v2.0 terminated successfully");
}