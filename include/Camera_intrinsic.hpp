#pragma once

#include "Record.hpp"
#include "RecordVisitor.hpp"
#include "extern/nlohmann/json.hpp"
#include <any>
#include <iostream>

using json = nlohmann::json;

class Camera_intrinsic : public Record {
  friend class NuScenes;

 private:
  std::any  intrinsic;
 public:
  void accept(const RecordVisitor &visitor) const override;
  Camera_intrinsic &operator=(const Camera_intrinsic &) = default;
  Camera_intrinsic &operator=(Camera_intrinsic &&) = default;

  Camera_intrinsic()=delete;
  Camera_intrinsic(const Camera_intrinsic &) = default;
  Camera_intrinsic(Camera_intrinsic &&) = default;
  Camera_intrinsic(const json &);
  //Camera_intrinsic(const std::any &x); // conflict with copy constructor in gcc v9.4 below 

  const std::any &get_intrinsic() const;
  void print() const; 
  ~Camera_intrinsic() = default;
};
