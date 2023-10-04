#pragma once

/**
 * @file CVector3D.h
 * @brief Contains the declaration of the CVector3D class.
 */

namespace Cali
{
    /**
     * @class CVector3D
     * @brief Represents a 3D vector.
     */
    template <typename T = double>
    class CVector3D
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

        /**
         * @brief The Z coordinate.
         * */
        T m_Z;

    public:
        /**
         * @brief Default constructor.
         * Initializes the vector with zero values.
         */
        CVector3D() : m_X(0), m_Y(0), m_Z(0) {}

        /**
         * @brief Parameterized constructor.
         * Initializes the vector with the specified values.
         * @param x The X coordinate.
         * @param y The Y coordinate.
         * @param z The Z coordinate.
         */
        CVector3D(T x, T y, T z) : m_X(x), m_Y(y), m_Z(z) {}

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
         * @brief Get the Z coordinate.
         * @return The Z coordinate.
         */
        T GetZ() const { return m_Z; }

        /**
         * @brief Set the X coordinate.
         * @param x The new X coordinate.
         */
        void SetX(T x) { m_X = x; }

        /**
         * @brief Set the Y coordinate.
         * @param y The new Y coordinate.
         */
        void SetY(T y) { m_Y = y; }

        /**
         * @brief Set the Z coordinate.
         * @param z The new Z coordinate.
         */
        void SetZ(T z) { m_Z = z; }

        /**
         * @brief Overloaded addition operator for CVector3D class.
         *
         * This operator adds the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param vec The CVector3D object to be added.
         * @return The result of the addition operation.
         */
        CVector3D operator+(const CVector3D &vec) const
        {
            // Create a new CVector3D object with the sum of the coordinates of the two objects
            return CVector3D(m_X + vec.m_X, m_Y + vec.m_Y, m_Z + vec.m_Z);
        }

        /**
         * @brief Overloaded subtraction operator for CVector3D class.
         *
         * This operator subtracts the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param vec The CVector3D object to be subtracted.
         * @return The result of the subtraction operation.
         */

        CVector3D operator-(const CVector3D &vec) const
        {
            // Create a new CVector3D object with the differences of the corresponding components
            CVector3D result(m_X - vec.m_X, m_Y - vec.m_Y, m_Z - vec.m_Z);

            // Return the new CVector3D object
            return result;
        }

        /**
         * @brief Overloaded multiplication operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param scalar The scalar value.
         * @return The result of the multiplication operation.
         * */
        CVector3D operator*(T scalar) const
        {
            return CVector3D(m_X * scalar, m_Y * scalar, m_Z * scalar);
        }

        /**
         * @brief Overloaded division operator for CVector3D class.
         *
         * This operator divides the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param scalar The scalar value.
         * @return The result of the division operation.
         * */

        CVector3D operator/(T scalar) const
        {
            return CVector3D(m_X / scalar, m_Y / scalar, m_Z / scalar);
        }

        /**
         * @brief Overloaded equality operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are equal, false otherwise.
         * */
        CVector3D &operator+=(const CVector3D &vec)
        {
            m_X += vec.m_X;
            m_Y += vec.m_Y;
            m_Z += vec.m_Z;
            return *this;
        }

        /**
         * @brief Overloaded subtraction operator for CVector3D class.
         *
         * This operator subtracts the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param vec The CVector3D object to be subtracted.
         * @return The result of the subtraction operation.
         * */
        CVector3D &operator-=(const CVector3D &vec)
        {
            m_X -= vec.m_X;
            m_Y -= vec.m_Y;
            m_Z -= vec.m_Z;
            return *this;
        }

        /**
         * @brief Overloaded multiplication operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param scalar The scalar value.
         * @return The result of the multiplication operation.
         * */
        CVector3D &operator*=(T scalar)
        {
            m_X *= scalar;
            m_Y *= scalar;
            m_Z *= scalar;
            return *this;
        }

        /**
         * @brief Overloaded division operator for CVector3D class.
         *
         * This operator divides the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param scalar The scalar value.
         * @return The result of the division operation.
         * */
        CVector3D &operator/=(T scalar)
        {
            m_X /= scalar;
            m_Y /= scalar;
            m_Z /= scalar;
            return *this;
        }

        /**
         * @brief Overloaded equality operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are equal, false otherwise.
         * */
        bool operator==(const CVector3D &vec) const
        {
            return m_X == vec.m_X && m_Y == vec.m_Y && m_Z == vec.m_Z;
        }

        /**
         * @brief Overloaded inequality operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are not equal, false otherwise.
         * */
        bool operator!=(const CVector3D &vec) const
        {
            return m_X != vec.m_X || m_Y != vec.m_Y || m_Z != vec.m_Z;
        }

        /**
         * @brief Overloaded less than operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are less than each other, false otherwise.
         * */
        bool operator<(const CVector3D &vec) const
        {
            return m_X < vec.m_X && m_Y < vec.m_Y && m_Z < vec.m_Z;
        }

        /**
         * @brief Overloaded less than operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are less than each other, false otherwise.
         * */
        bool operator<=(const CVector3D &vec) const
        {
            return m_X <= vec.m_X && m_Y <= vec.m_Y && m_Z <= vec.m_Z;
        }

        /**
         * @brief Overloaded greater than operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are greater than each other, false otherwise.
         * */
        bool operator>(const CVector3D &vec) const
        {
            return m_X > vec.m_X && m_Y > vec.m_Y && m_Z > vec.m_Z;
        }

        /**
         * @brief Overloaded greater than operator for CVector3D class.
         *
         * This operator compares the coordinates of two CVector3D objects and returns a boolean value.
         *
         * @param vec The CVector3D object to be compared.
         * @return True if the coordinates of the two objects are greater than each other, false otherwise.
         * */

        bool operator>=(const CVector3D &vec) const
        {
            return m_X >= vec.m_X && m_Y >= vec.m_Y && m_Z >= vec.m_Z;
        }

        /**
         *
         * @brief Overloaded dot product operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a scalar value.
         *
         * @param vec The CVector3D object to be multiplied.
         * @return The result of the dot product operation.
         * */
        T GetDistance(const CVector3D &vec) const
        {
            return sqrt((m_X - vec.m_X) * (m_X - vec.m_X) + (m_Y - vec.m_Y) * (m_Y - vec.m_Y) + (m_Z - vec.m_Z) * (m_Z - vec.m_Z));
        }

        /**
         *
         * @brief Overloaded dot product operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a scalar value.
         *
         * @param vec The CVector3D object to be multiplied.
         * @return The result of the dot product operation.
         * */
        T GetDistanceSq(const CVector3D &vec) const
        {
            return (m_X - vec.m_X) * (m_X - vec.m_X) + (m_Y - vec.m_Y) * (m_Y - vec.m_Y) + (m_Z - vec.m_Z) * (m_Z - vec.m_Z);
        }

        /**
         * @brief Overloaded cross product operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param vec The CVector3D object to be multiplied.
         * @return The result of the cross product operation.
         * */
        CVector3D Cross(const CVector3D &vec) const
        {
            return CVector3D(m_Y * vec.m_Z - m_Z * vec.m_Y, m_Z * vec.m_X - m_X * vec.m_Z, m_X * vec.m_Y - m_Y * vec.m_X);
        }

        /**
         * @brief Overloaded dot product operator for CVector3D class.
         *
         * This operator multiplies the coordinates of two CVector3D objects and returns a scalar value.
         *
         * @param vec The CVector3D object to be multiplied.
         * @return The result of the dot product operation.
         * */
        T Dot(const CVector3D &vec) const
        {
            return m_X * vec.m_X + m_Y * vec.m_Y + m_Z * vec.m_Z;
        }

        /**
         * @brief Calculates the length of a vector.
         *
         * @return The length of the vector.
         */
        T Length() const
        {
            return sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
        }

        /**
         * @brief Calculates the squared length of a vector.
         *
         * @return The squared length of the vector.
         */
        T LengthSq() const
        {
            // Calculate the squared length of the vector
            return m_X * m_X + m_Y * m_Y + m_Z * m_Z;
        }

        /**
         * @brief Normalize the vector.
         *
         * This function normalizes the vector by dividing each component
         * by the length of the vector.
         */
        void Normalize()
        {
            T length = Length();
            *this = CVector3D(m_X / length, m_Y / length, m_Z / length);
        }

        /**
         * @brief Calculates the normalized vector of the current vector.
         *
         * @return The normalized vector.
         */
        CVector3D Normalized() const
        {
            T length = Length();
            return CVector3D(m_X / length, m_Y / length, m_Z / length);
        }

        /**
         * @brief Overloaded assignment operator for CVector3D class.
         *
         * This operator assigns the coordinates of two CVector3D objects and returns a new CVector3D object.
         *
         * @param vec The CVector3D object to be assigned.
         * @return The result of the assignment operation.
         * */
        CVector3D &operator=(const CVector3D &vec)
        {
            m_X = vec.m_X;
            m_Y = vec.m_Y;
            m_Z = vec.m_Z;
            return *this;
        }

        /**
         * @brief Overloaded negation operator for CVector3D class.
         *
         * This operator negates the coordinates of a CVector3D object and returns a new CVector3D object.
         *
         * @return The result of the negation operation.
         * */
        CVector3D operator-() const
        {
            return CVector3D(-m_X, -m_Y, -m_Z);
        }

        /**
         * @brief Get the angle between two CVector3D objects.
         * @param vec The other CVector3D object.
         * @return The angle between the two vectors.
         */
        CVector3D GetAngle(const CVector3D &vec) const
        {
            return acos(Dot(vec) / (Length() * vec.Length()));
        }

        /**
         * @brief Get the orthogonal vector of the current vector in the xy-plane.
         *
         * @return The orthogonal vector.
         */
        CVector3D GetOrthogonal() const
        {
            // The orthogonal vector in the xy-plane can be obtained by swapping the
            // x and y components and negating the new x component.
            return CVector3D(m_Y, -m_X, 0);
        }

        /**
         * @brief Get the perpendicular vector to the current vector in the XY plane.
         *
         * @return The perpendicular vector.
         */
        CVector3D GetPerpendicular() const
        {
            // Create a new vector with the components swapped and the Z component set to 0.
            return CVector3D(-m_Y, m_X, 0);
        }
    };
} // namespace Cali
