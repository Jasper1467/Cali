#include "CDrawManager.h"

#include "DrawManagers/CDrawManager_D3D9.h"

Cali::CDrawManager_D3D9 *m_pDrawManager_D3D9 = new Cali::CDrawManager_D3D9();

void Cali::CDrawManager::Initialize()
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->Initialize();

    m_bInitialized = true;
}

void Cali::CDrawManager::Shutdown()
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->Shutdown();

    m_bInitialized = false;
}

template <typename T>
void Cali::CDrawManager::DrawLine(CVector2D<T> v1, CVector2D<T> v2)
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->DrawLine(v1, v2);
}

template <typename T>
void Cali::CDrawManager::DrawRect(CVector2D<T> v1, CVector2D<T> v2)
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->DrawRect(v1, v2);
}

template <typename T>
void Cali::CDrawManager::DrawCircle(CVector2D<T> v1, double radius)
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->DrawCircle(v1, radius);
}

template <typename T>
void Cali::CDrawManager::DrawTriangle(CVector2D<T> v1, CVector2D<T> v2, CVector2D<T> v3)
{
    if (m_nManagerType == ManagerType_e::D3D9)
        m_pDrawManager_D3D9->DrawTriangle(v1, v2, v3);
}