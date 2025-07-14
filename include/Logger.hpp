#pragma once

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

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
  // expects directory of input filepath to exist
  Logger(std::optional<std::string> filepath = std::nullopt)
  {
    if (!filepath.has_value())
    {
      filepath = make_xdg_filepath();
    }

    add_file_stream(filepath.value());
  }

  void log(const std::string &msg, Level level = Level::INFO)
  {
    std::stringstream ss;

    ss << "[" << make_current_timestamp() << "] ";

    ss << level_to_string(level) << ": ";

    ss << msg;
    ss << "\n";

    for (std::ostream *os : streams)
    {
      *os << ss.str();
    }
  };

  void info(const std::string &msg) { log(msg, Level::INFO); }
  void warning(const std::string &msg) { log(msg, Level::WARNING); }
  void error(const std::string &msg) { log(msg, Level::ERROR); }
  void critical(const std::string &msg) { log(msg, Level::CRITICAL); }

  void add_file_stream(const std::string &filepath)
  {
    auto file_stream = std::make_unique<std::ofstream>(filepath);
    if (!file_stream->is_open())
    {
      throw std::runtime_error("Error opening logfile: " + filepath);
    }

    streams.push_back(file_stream.get());
    file_streams.push_back(std::move(file_stream));
  }

  void add_stream(std::ostream &os) { streams.push_back(&os); }

private:
  std::vector<std::ostream *> streams = {};                      // all streams to write logs
  std::vector<std::unique_ptr<std::ofstream>> file_streams = {}; // ofstreams that need ownership

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

  std::string make_xdg_filepath()
  {
    const char *home = std::getenv("HOME");
    const std::string suffix = "/.local/share/chesspp/log/";
    std::filesystem::create_directories(std::string(home) + suffix);
    return std::string(home) + suffix + "test.log"; // TODO: change filename
  }
};

extern Logger logger;