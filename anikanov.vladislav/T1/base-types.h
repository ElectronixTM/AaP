#ifndef BASE_TYPES_H
#define BASE_TYPES_H

#include <iosfwd>

struct PointT {
  double x;
  double y;

  explicit PointT();

  explicit PointT(double x, double y);

  PointT &operator=(PointT another_point);

  friend std::istream &operator>>(std::istream &, PointT &);
  friend std::ostream &operator<<(std::ostream &, const PointT &);
};

struct RectangleT {
  double width;
  double height;
  PointT pos;

  explicit RectangleT();
  explicit RectangleT(PointT pos, double width, double height);

  friend std::ostream &operator<<(std::ostream &, const RectangleT &);
};

#endif
