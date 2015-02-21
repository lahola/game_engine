//
//  Vector.h
//  Math
//
//  Created by Louis Ahola on 5/26/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#pragma once
#include <cmath>

template <class T>
class Vector2
{
public:
    Vector2() {}
    Vector2(T x, T y) : x(x), y(y) {}

public:
    T x;
    T y;
};

template <class T>
class Vector3
{
public:
    Vector3() {}
    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

    void normalize()
    {
        float length = std::sqrt(x * x + y * y + z * z);
        x /= length;
        y /= length;
        z /= length;
    }
    
    Vector3 cross(const Vector3& v) const
    {
        return Vector3(y * v.z - z * v.y,
                       z * v.x - x * v.z,
                       x * v.y - y * v.x);
    }
    
    T dot(const Vector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    
    Vector3 operator-() const
    {
        return Vector3(-x, -y, -z);
    }
    
    bool operator==(const Vector3& v) const
    {
        return x == v.x && y == v.y && z == v.z);
    }
    
public:
    T x;
    T y;
    T z;
};

template <class T>
class Vector4
{
    
};

typedef Vector2<int> ivec2;
typedef Vector3<int> ivec3;
typedef Vector4<int> ivec4;

typedef Vector2<float> vec2;
typedef Vector3<float> vec3;
typedef Vector4<float> vec4;