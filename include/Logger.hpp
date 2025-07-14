#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum class Level
{
  INFO,
  WARNING,
  ERROR,
  CRITICAL,
};

class Logger
{
public:
  Logger(const std::string &filepath, const bool stdout = true) : log_to_stdout(stdout)
  {
    ostream = std::ofstream(filepath);
    if (!ostream)
    {
      throw std::runtime_error("Error opening logfile: " + filepath);
    }
  }

  ~Logger() { ostream.close(); }

  void log(const std::string &msg, Level level = Level::INFO)
  {
    std::stringstream ss;

    ss << "[" << make_current_timestamp() << "] ";

    ss << level_to_string(level) << ": ";

    ss << msg;
    ss << "\n";

    ostream << ss.str();
    if (log_to_stdout)
    {
      std::cout << ss.str();
    }
  };

  void info(const std::string &msg) { log(msg, Level::INFO); }
  void warning(const std::string &msg) { log(msg, Level::WARNING); }
  void error(const std::string &msg) { log(msg, Level::ERROR); }
  void critical(const std::string &msg) { log(msg, Level::CRITICAL); }

private:
  std::ofstream ostream;
  bool log_to_stdout;

  std::string level_to_string(Level level)
  {
    switch (level)
    {
    case Level::INFO:
      return "INFO";
    case Level::WARNING:
      return "WARNING";
    case Level::ERROR:
      return "ERROR";
    case Level::CRITICAL:
      return "CRITICAL";
    default:
      return "INFO";
    }
  };

  std::string make_current_timestamp()
  {
    const auto t = std::time(nullptr);
    const auto timeinfo = std::localtime(&t);

    constexpr size_t timestamp_size = 20;
    char time_string[timestamp_size];
    std::strftime(time_string, timestamp_size, "%Y-%m-%d %H:%M:%S", timeinfo);

    return std::string(time_string);
  }
};

extern Logger logger;