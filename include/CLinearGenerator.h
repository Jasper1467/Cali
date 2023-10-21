#pragma once

#include <vector>
#include <type_traits>

namespace Cali
{
    template <typename T>
    class CLinearGenerator
    {
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

    private:
        std::vector<T> m_Calculated;
        T m_Min;
        T m_Max;
        T m_Step;

        void CalculateLinear()
        {
            for (int i = m_Min; i < (m_Max - m_Min); i++)
                m_Calculated[i] = i * m_Step;
        }

    public:
        CLinearGenerator(T Min, T Max, T Step)
        {
            m_Min = Min;
            m_Max = Max;
            m_Step = Step;

            CalculateLinear();
        }

        std::vector<T> GetCalculated()
        {
            return m_Calculated;
        }
    };
} // namespace Cali