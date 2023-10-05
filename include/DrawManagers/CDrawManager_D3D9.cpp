#include "CDrawManager_D3D9.h"

void Cali::CDrawManager_D3D9::Initialize()
{
    m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, nullptr, D3DCREATE_SOFTWARE_VERTEXPROCESSING, nullptr, &m_pD3DDevice);
}

void Cali::CDrawManager_D3D9::Shutdown()
{
    m_pD3DDevice->Release();
    m_pD3D->Release();

    m_pD3DDevice = nullptr;
    m_pD3D = nullptr;
}