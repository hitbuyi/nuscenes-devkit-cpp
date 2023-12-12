#pragma once

#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Scene {
 private:
  std::string token;
  std::string log_token;
  size_t nbr_samples;
  std::string first_sample_token;
  std::string last_sample_token;
  std::string name;
  std::string description;

 public:
  const std::string &get_token() const;
  const std::string &get_log_token() const;
  const size_t &get_nbr_samples() const;
  const std::string &get_first_sample_token() const;
  const std::string &get_last_sample_token() const;
  const std::string &get_name() const;
  const std::string &get_description() const;
  Scene() = delete;
  Scene(const json &);
  Scene(std::string, std::string, size_t, std::string, std::string, std::string,
        std::string);
  ~Scene() = default;
};
