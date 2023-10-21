#pragma once

#include <vector>
#include <type_traits>

namespace Cali
{
    template<typename T>
    class CGaussian
    {
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
    private:
        std::vector<T> m_Calculated;
        std::vector<T> m_Data = {};
        T m_Mean;
        T m_Std;

        void CalculateGaussian()
        {
            for (int i = 0; i < m_Data.size(); i++)
            {
                m_Calculated[i] = exp(-(m_Data[i] - m_Mean) * (m_Data[i] - m_Mean) / (2 * m_Std * m_Std));
                m_Calculated[i] /= sqrt(2 * M_PI) * m_Std;
            }
        }

    public:
        explicit CGaussian(T Mean, T Std, std::vector<T> Data)
        {
            if (!Data.size())
                return;

            m_Mean = Mean;
            m_Std = Std;
            m_Data = Data;

            CalculateGaussian();
        }

        std::vector<T> GetCalculated()
        {
            return m_Calculated;
        }

        T GetMean()
        {
            return m_Mean;
        }

        T GetStd()
        {
            return m_Std;
        }
    };
        
} // namespace Cali
