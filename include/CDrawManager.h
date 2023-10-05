#pragma once

#include <atomic>
#include <mutex>
#include "CVector2D.h"

namespace Cali
{
    class CDrawManager
    {
    public:
        enum ManagerType_e
        {
            D3D9 = 0,
            D3D11
        };

    private:
        ManagerType_e m_nManagerType;
        std::mutex m_Mutex;
        std::atomic<bool> m_bInitialized = false;

    public:
        void Initialize();
        void Shutdown();

        template <typename T = float>
        void DrawLine(CVector2D<T> v1, CVector2D<T> v2);

        template <typename T = float>
        void DrawRect(CVector2D<T> v1, CVector2D<T> v2);

        template <typename T = float>
        void DrawCircle(CVector2D<T> v1, double radius);

        template <typename T = float>
        void DrawTriangle(CVector2D<T> v1, CVector2D<T> v2, CVector2D<T> v3);
    };

} // namespace Cali
