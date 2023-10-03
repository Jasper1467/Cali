#pragma once

namespace Cali
{
    template <typename T = double>
    class CVector2D
    {
    private:
        T m_X;
        T m_Y;

    public:
        CVector2D() : m_X(0), m_Y(0) {}
        CVector2D(T x, T y) : m_X(x), m_Y(y) {}

        T GetX() const { return m_X; }
        T GetY() const { return m_Y; }

        void SetX(T x) { m_X = x; }
        void SetY(T y) { m_Y = y; }

        CVector2D operator+(const CVector2D &vec) const
        {
            return CVector2D(m_X + vec.m_X, m_Y + vec.m_Y);
        }

        CVector2D operator-(const CVector2D &vec) const
        {
            return CVector2D(m_X - vec.m_X, m_Y - vec.m_Y);
        }

        CVector2D operator*(T scalar) const
        {
            return CVector2D(m_X * scalar, m_Y * scalar);
        }

        CVector2D operator/(T scalar) const
        {
            return CVector2D(m_X / scalar, m_Y / scalar);
        }

        CVector2D &operator+=(const CVector2D &vec)
        {
            m_X += vec.m_X;
        }

        CVector2D &operator-=(const CVector2D &vec)
        {
            m_X -= vec.m_X;
        }

        CVector2D &operator*=(T scalar)
        {
            m_X *= scalar;
        }

        CVector2D &operator/=(T scalar)
        {
            m_X /= scalar;
        }

        bool operator==(const CVector2D &vec) const
        {
            return m_X == vec.m_X && m_Y == vec.m_Y;
        }

        bool operator!=(const CVector2D &vec) const
        {
            return m_X != vec.m_X || m_Y != vec.m_Y;
        }

        bool operator<(const CVector2D &vec) const
        {
            return m_X < vec.m_X && m_Y < vec.m_Y;
        }

        bool operator<=(const CVector2D &vec) const
        {
            return m_X <= vec.m_X && m_Y <= vec.m_Y;
        }

        bool operator>(const CVector2D &vec) const
        {
            return m_X > vec.m_X && m_Y > vec.m_Y;
        }

        bool operator>=(const CVector2D &vec) const
        {
            return m_X >= vec.m_X && m_Y >= vec.m_Y;
        }

        CVector2D &operator=(const CVector2D &vec)
        {
            m_X = vec.m_X;
            m_Y = vec.m_Y;
            return *this;
        }

        CVector2D operator-() const
        {
            return CVector2D(-m_X, -m_Y);
        }

        T Length() const
        {
            return sqrt(m_X * m_X + m_Y * m_Y);
        }

        T LengthSq() const
        {
            return m_X * m_X + m_Y * m_Y;
        }

        T Dot(const CVector2D &vec) const
        {
            return m_X * vec.m_X + m_Y * vec.m_Y;
        }

        CVector2D Cross(const CVector2D &vec) const
        {
            return CVector2D(m_Y * vec.m_X - m_X * vec.m_Y, m_X * vec.m_Y - m_Y * vec.m_X);
        }

        CVector2D Normalized() const
        {
            T length = Length();
            return CVector2D(m_X / length, m_Y / length);
        }

        CVector2D &Normalize()
        {
            T length = Length();
            m_X /= length;
            m_Y /= length;
            return *this;
        }

        T GetAngle(const CVector2D &vec) const
        {
            return acos(Dot(vec) / (Length() * vec.Length()));
        }

        CVector2D GetPerpendicular() const
        {
            return CVector2D(-m_Y, m_X);
        }

        CVector2D GetOrthogonal() const
        {
            return CVector2D(m_Y, -m_X);
        }

        T GetDistance(const CVector2D &vec) const
        {
            return (vec - *this).Length();
        }

        T GetDistanceSq(const CVector2D &vec) const
        {
            return (vec - *this).LengthSq();
        }
    };

} // namespace Cali
