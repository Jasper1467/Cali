#pragma once

#include <d3d9.h>

#include "../CVector2D.h"

namespace Cali
{
    class CDrawManager_D3D9
    {
    private:
        LPDIRECT3D9 m_pD3D;
        LPDIRECT3DDEVICE9 m_pD3DDevice;

    public:
        CDrawManager_D3D9() { Initialize(); }
        ~CDrawManager_D3D9() { Shutdown(); }

        void Initialize();
        void Shutdown();

        LPDIRECT3D9 GetD3D() { return m_pD3D; }
        LPDIRECT3DDEVICE9 GetDevice() { return m_pD3DDevice; }

        D3DVIEWPORT9 GetViewport() const
        {
            D3DVIEWPORT9 viewport;
            m_pD3DDevice->GetViewport(&viewport);
        }

        void SetViewport(D3DVIEWPORT9 viewport)
        {
            m_pD3DDevice->SetViewport(&viewport);
        }

        template<typename T = float>
        void DrawLine(CVector2D<T> v1, CVector2D<T> v2)
        {
            m_pD3DDevice->DrawLine(v1.GetX(), v1.GetY(), v2.GetX(), v2.GetY());
        }

        template<typename T = float>
        void DrawRect(CVector2D<T> v1, CVector2D<T> v2)
        {
            m_pD3DDevice->DrawRect(v1.GetX(), v1.GetY(), v2.GetX(), v2.GetY());
        }

        template<typename T = float>
        void DrawCircle(CVector2D<T> v1, double radius)
        {
            m_pD3DDevice->DrawCircle(v1.GetX(), v1.GetY(), radius);
        }

        template<typename T = float>
        void DrawTriangle(CVector2D<T> v1, CVector2D<T> v2, CVector2D<T> v3)
        {
            m_pD3DDevice->DrawTriangle(v1.GetX(), v1.GetY(), v2.GetX(), v2.GetY(), v3.GetX(), v3.GetY());
        }
    };
} // namespace Cali