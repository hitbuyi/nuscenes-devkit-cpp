#pragma once

#include <filesystem>
#include <string>

#include "nlohmann/json.hpp"

class Sample;
class EgoPosition;
class CalibratedSensor;

using json = nlohmann::json;
namespace fs = std::filesystem;

class SampleData {
  friend class NuScenes;

 private:
  std::string token;
  std::string sample_token;
  std::string ego_pose_token;
  std::string calibrated_sensor_token;
  uint64_t timestamp;
  std::string fileformat;
  bool is_key_frame;
  size_t width;
  size_t height;
  fs::path filename;
  std::string prev_token;
  std::string next_token;

  Sample *sample;
  EgoPosition *ego_pose;
  CalibratedSensor *calibrated_sensor;
  SampleData *prev;
  SampleData *next;

 public:
  const std::string &get_token() const;
  const std::string &get_sample_token() const;
  const std::string &get_ego_pose_token() const;
  const std::string &get_calibrated_sensor_token() const;
  const uint64_t &get_timestamp() const;
  const std::string &get_fileformat() const;
  const bool &get_is_key_frame() const;
  const size_t &get_width() const;
  const size_t &get_height() const;
  const fs::path &get_filename() const;
  const std::string &get_prev_token() const;
  const std::string &get_next_token() const;

  SampleData &operator=(const SampleData &) = default;

  SampleData() = delete;
  SampleData(const json &);
  SampleData(std::string, std::string, std::string, std::string, uint64_t,
             std::string, bool, size_t, size_t, fs::path, std::string,
             std::string);
  ~SampleData() = default;
};