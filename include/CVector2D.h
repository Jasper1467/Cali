#pragma once

/**
 * @file CVector2D.h
 * @brief Contains the declaration of the CVector2D class.
 */

namespace Cali
{
    /**
     * @class CVector2D
     * @brief Represents a 2D vector.
     */
    template <typename T = double>
    class CVector2D
    {
    private:
        /**
         * @brief The X coordinate.
         * */
        T m_X;

        /**
         * @brief The Y coordinate.
         * */
        T m_Y;

    public:
        /**
         * @brief Default constructor.
         * Initializes the vector with zero values.
         * */
        CVector2D() : m_X(0), m_Y(0) {}

        /**
         * @brief Parameterized constructor.
         * Initializes the vector with the specified values.
         * @param x The X coordinate.
         * @param y The Y coordinate.
         * */
        CVector2D(T x, T y) : m_X(x), m_Y(y) {}

        /**
         * @brief Get the X coordinate.
         * @return The X coordinate.
         */
        T GetX() const { return m_X; }

        /**
         * @brief Get the Y coordinate.
         * @return The Y coordinate.
         */
        T GetY() const { return m_Y; }

        /**
         * @brief Set the X coordinate.
         * @param x The new X coordinate.
         * */
        void SetX(T x) { m_X = x; }

        /**
         * @brief Set the Y coordinate.
         * @param y The new Y coordinate.
         * */
        void SetY(T y) { m_Y = y; }

        /**
         * @brief Add two vectors.
         * @param vec The vector to add.
         * @return The result of the addition.
         * */
        CVector2D operator+(const CVector2D &vec) const
        {
            return CVector2D(m_X + vec.m_X, m_Y + vec.m_Y);
        }

        /**
         * @brief Subtract two vectors.
         * @param vec The vector to subtract.
         * @return The result of the subtraction.
         * */
        CVector2D operator-(const CVector2D &vec) const
        {
            return CVector2D(m_X - vec.m_X, m_Y - vec.m_Y);
        }

        /**
         * @brief Overloaded multiplication operator for CVector2D class.
         *
         * This operator multiplies the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param scalar The scalar value.
         * @return The result of the multiplication operation.
         * */
        CVector2D operator*(T scalar) const
        {
            return CVector2D(m_X * scalar, m_Y * scalar);
        }

        /**
         * @brief Overloaded division operator for CVector2D class.
         *
         * This operator divides the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param scalar The scalar value.
         * @return The result of the division operation.
         * */
        CVector2D operator/(T scalar) const
        {
            return CVector2D(m_X / scalar, m_Y / scalar);
        }

        /**
         * @brief Overloaded addition operator for CVector2D class.
         *
         * This operator adds the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param vec The CVector2D object to be added.
         * @return The result of the addition operation.
         * */
        CVector2D &operator+=(const CVector2D &vec)
        {
            m_X += vec.m_X;
        }

        /**
         * @brief Overloaded subtraction operator for CVector2D class.
         *
         * This operator subtracts the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param vec The CVector2D object to be subtracted.
         * @return The result of the subtraction operation.
         * */
        CVector2D &operator-=(const CVector2D &vec)
        {
            m_X -= vec.m_X;
        }

        /**
         * @brief Overloaded multiplication operator for CVector2D class.
         *
         * This operator multiplies the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param scalar The scalar value.
         * @return The result of the multiplication operation.
         * */
        CVector2D &operator*=(T scalar)
        {
            m_X *= scalar;
        }

        /**
         * @brief Overloaded division operator for CVector2D class.
         *
         * This operator divides the coordinates of two CVector2D objects and returns a new CVector2D object.
         *
         * @param scalar The scalar value.
         * @return The result of the division operation.
         * */
        CVector2D &operator/=(T scalar)
        {
            m_X /= scalar;
        }

        /**
         * @brief Overloaded equality operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         */
        bool operator==(const CVector2D &vec) const
        {
            return m_X == vec.m_X && m_Y == vec.m_Y;
        }

        /**
         * @brief Overloaded inequality operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         */
        bool operator!=(const CVector2D &vec) const
        {
            return m_X != vec.m_X || m_Y != vec.m_Y;
        }

        /**
         * @brief Overloaded less than operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         */
        bool operator<(const CVector2D &vec) const
        {
            return m_X < vec.m_X && m_Y < vec.m_Y;
        }

        /**
         * @brief Overloaded less than or equal operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         */
        bool operator<=(const CVector2D &vec) const
        {
            return m_X <= vec.m_X && m_Y <= vec.m_Y;
        }

        /**
         * @brief Overloaded greater than operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         * */
        bool operator>(const CVector2D &vec) const
        {
            return m_X > vec.m_X && m_Y > vec.m_Y;
        }

        /**
         * @brief Overloaded greater than or equal operator for CVector2D class.
         * @param vec The CVector2D object to be compared.
         * */
        bool operator>=(const CVector2D &vec) const
        {
            return m_X >= vec.m_X && m_Y >= vec.m_Y;
        }

        /**
         * @brief Overloaded assignment operator for CVector2D class.
         * @param vec The CVector2D object to be assigned.
         */
        CVector2D &operator=(const CVector2D &vec)
        {
            m_X = vec.m_X;
            m_Y = vec.m_Y;
            return *this;
        }

        /**
         * @brief Overloaded negation operator for CVector2D class.
         * @param vec The CVector2D object to be negated.
         * */
        CVector2D operator-() const
        {
            return CVector2D(-m_X, -m_Y);
        }

        /**
         * @brief Get the length of the vector.
         * @return The length of the vector.
         * */
        T Length() const
        {
            return sqrt(m_X * m_X + m_Y * m_Y);
        }

        /**
         * @brief Get the squared length of the vector.
         * @return The squared length of the vector.
         * */
        T LengthSq() const
        {
            return m_X * m_X + m_Y * m_Y;
        }

        /**
         * @brief Normalize the vector.
         * This function normalizes the vector by dividing each component
         * by the length of the vector.
         */
        void Normalize()
        {
            T length = Length();
            *this = CVector2D(m_X / length, m_Y / length);
        }

        /**
         * @brief Calculates the normalized vector of the current vector.
         * @return The normalized vector.
         * */
        CVector2D Normalized() const
        {
            T length = Length();
            return CVector2D(m_X / length, m_Y / length);
        }

        /**
         * @brief Calculates the dot product of two vectors.
         * @param vec The CVector2D object to be compared.
         * @return The result of the dot product operation.
         * */
        T Dot(const CVector2D &vec) const
        {
            return m_X * vec.m_X + m_Y * vec.m_Y;
        }

        /**
         * @brief Calculates the cross product of two vectors.
         * @param vec The CVector2D object to be compared.
         * @return The result of the cross product operation.
         * */
        CVector2D Cross(const CVector2D &vec) const
        {
            return CVector2D(m_Y * vec.m_X - m_X * vec.m_Y, m_X * vec.m_Y - m_Y * vec.m_X);
        }

        /**
         * @brief Calculates the angle between two vectors.
         * @param vec The other CVector2D object.
         * @return The angle between the two vectors.
         * */
        T GetAngle(const CVector2D &vec) const
        {
            return acos(Dot(vec) / (Length() * vec.Length()));
        }

        /**
         * @brief Get the perpendicular vector.
         * @return The perpendicular vector.
         * */
        CVector2D GetPerpendicular() const
        {
            return CVector2D(-m_Y, m_X);
        }

        /**
         * @brief Get the orthogonal vector.
         * @return The orthogonal vector.
         * */
        CVector2D GetOrthogonal() const
        {
            return CVector2D(m_Y, -m_X);
        }

        /**
         * @brief Get the distance between two vectors.
         * @param vec The other CVector2D object.
         * @return The distance between the two vectors.
         * */
        T GetDistance(const CVector2D &vec) const
        {
            return (vec - *this).Length();
        }

        /**
         * @brief Get the distance squared between two vectors.
         * @param vec The other CVector2D object.
         * @return The distance squared between the two vectors.
         * */
        T GetDistanceSq(const CVector2D &vec) const
        {
            return (vec - *this).LengthSq();
        }
    };

} // namespace Cali
