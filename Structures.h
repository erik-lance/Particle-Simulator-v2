#pragma once

// PI Constant
constexpr auto PI = 3.14159265358979323846;

struct Position { double x; double y; };
struct Line { Position start; Position end; double angle; };
struct Screen { int width = 1280; int height = 720; };

static inline bool operator==(const Position& lhs, const Position& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

// Function to normalize angle in Radians [0, 2pi]
static inline double normalizeAngle(double angle)
{
    // Normalize the angle to be between 0 and 2pi
    while (angle < 0) { angle += 2.0 * PI; }
    while (angle > 2 * PI) { angle -= 2.0 * PI; }
    return angle;
}

// Function to reflect angle in Radians
static inline double reflectAngle(double angle, double line_angle)
{
    // Reflection formula
    angle = 2 * line_angle - angle;

    angle = normalizeAngle(angle);
	return angle;
}